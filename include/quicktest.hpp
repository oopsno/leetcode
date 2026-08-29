#pragma once

#include <fmt/color.h>
#include <fmt/core.h>
#include <fmt/ranges.h>

#include <functional>
#include <type_traits>

#include "leetcode.hpp"

namespace quicktest {

template <typename T, typename D>
using disable_if_is_t = std::enable_if_t<not std::is_same_v<T, D>, D>;

template <typename T, typename E>
using enable_if_is_t = std::enable_if_t<std::is_same_v<T, E>, E>;

template <typename T, typename U = std::remove_cvref_t<T>>
U deserialize(std::string literal) {
  return leetcode::deserializer<U>()(literal);
}

template<typename T>
struct is_vector_t : std::bool_constant<false> {};

template<typename T>
struct is_vector_t<std::vector<T>> : std::bool_constant<true> {};

template<typename T>
constexpr bool is_vector_v = is_vector_t<T>::value;

template <typename ValueType>
struct Thunk {
  using value_type = ValueType;
  value_type expected, actual;

  Thunk(value_type &&expected, value_type &&actual)
      : expected(expected), actual(actual) {}

  bool compare(size_t ith, size_t total) const {
    const auto passed = fmt::fg(fmt::color::light_green);
    const auto failed = fmt::fg(fmt::color::orange_red);
    bool equal = false, supported = true;
    std::string expected_display, actual_display;
    if constexpr (not std::is_pointer_v<value_type>) {
      equal = expected == actual;
      expected_display = fmt::format("{}", expected);
      actual_display = fmt::format("{}", actual);
    } else if constexpr (std::is_same_v<leetcode::ListNode*, value_type>) {
      expected_display = leetcode::listNodeToString(expected);
      actual_display = leetcode::listNodeToString(actual);
      equal = expected_display == actual_display;
    } else if constexpr (std::is_same_v<leetcode::TreeNode*, value_type>) {
      expected_display = leetcode::treeNodeToString(expected);
      actual_display = leetcode::treeNodeToString(actual);
      equal = expected_display == actual_display;
    } else {
      supported = false;
    }
    if (supported) {
      if (equal) {
        fmt::print(passed, "[{} / {}] expected {}, got {}\n", ith, total,
                   expected_display, actual_display);
        return true;
      } else {
        fmt::print(failed, "[{} / {}] expected {}, got {}\n", ith, total,
                   expected_display, actual_display);
        return false;
      }
    } else {
      const auto not_impl = fmt::fg(fmt::color::gray);
      fmt::print(not_impl, "[{} / {}] case not supported\n", ith, total);
      return false;
    }
  }
};

template <typename ValueType>
struct Result {
  using value_type = ValueType;
  value_type actual;

  explicit Result(value_type &&actual) : actual(actual) {}

  template <typename Mapped>
  Result<Mapped> map(std::function<Mapped(ValueType)> functor) {
    return Result<Mapped>(functor(actual));
  }

  Thunk<value_type> should_be(const char *expected_literal) {
    return should_be(deserialize<value_type>(expected_literal));
  }

  Thunk<value_type> should_be(value_type expected) {
    return Thunk<value_type>(std::move(expected), std::move(actual));
  }
};

template <typename BindedSolution, typename Output, typename... Input>
struct EndPoint {
  using solution_type = BindedSolution;
  using output_type = Output;
  using input_type = std::tuple<Input...>;
  using fn_type = Output (BindedSolution::*)(Input...);

  int id;
  BindedSolution solution;
  fn_type fn;

  EndPoint() = delete;

  EndPoint(int id, fn_type &&fn) : id{id}, fn{fn}, solution{} {}

  solution_type *operator->() { return &solution; }

  solution_type &operator*() { return solution; }

  output_type operator()(std::remove_cvref_t<Input>... input) {
    return (solution.*fn)(input...);
  }

  template <typename Value> using literal_t = const char *;

  Result<output_type> result_of(std::remove_cvref_t<Input>... input) {
    return Result<output_type>(operator()(input...));
  }

  Result<output_type> result_of(literal_t<Input>... input) {
    return Result<output_type>(operator()(deserialize<std::remove_cvref_t<Input>>(input)...));
  }

  template<typename R, typename... Args>
  Result<R> result_of(R (BindedSolution::* method)(Args...), Args... args) {
    return Result<R>((solution.*method)(args...));
  }

  template<typename R, typename... Args>
  Result<R> result_of(R (BindedSolution::* method)(Args...), literal_t<Args>... args) {
    return Result<R>((solution.*method)(deserialize<std::remove_cvref_t<Input>>(args)...));
  }

  template <typename CompareType=output_type>
  int ensure(std::vector<Thunk<CompareType>> thunks) const {
    size_t passed = 0;
    for (size_t i = 0; i < thunks.size(); ++i) {
      if (thunks[i].compare(i + 1, thunks.size())) {
        passed += 1;
      }
    }
    const auto style = fmt::fg(fmt::color::light_green);
    fmt::print(style, "[{} / {}] cases passed\n", passed, thunks.size());
    return passed != thunks.size();
  }
};

}  // namespace quicktest