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
bool is_vector_v = is_vector_t<T>::value;

template <typename ValueType>
struct Thunk {
  using value_type = ValueType;
  value_type expected, actual;

  Thunk(value_type &&expected, value_type &&actual)
      : expected(expected), actual(actual) {}

  bool compare(size_t ith, size_t total) const {
    const auto passed = fmt::fg(fmt::color::light_green);
    const auto failed = fmt::fg(fmt::color::orange_red);
    if constexpr (std::is_integral_v<value_type> or is_vector_v<value_type>) {
      if (expected != actual) {
        fmt::print(failed, "[{} / {}] expected {}, got {}\n", ith, total,
                   expected, actual);
        return false;
      } else {
        fmt::print(passed, "[{} / {}] expected {}, got {}\n", ith, total,
                   expected, actual);
        return true;
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

  template <typename = disable_if_is_t<value_type, std::string>>
  Thunk<value_type> should_be(std::string expected_literal) {
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

  BindedSolution solution;
  fn_type fn;

  explicit EndPoint(fn_type &&fn) : fn{fn}, solution{} {}

  output_type operator()(std::remove_cvref_t<Input>... input) {
    return (solution.*fn)(input...);
  }

  output_type operator()(disable_if_is_t<Input, std::string>... input) {
    return operator()(deserialize<Input>(input)...);
  }

  Result<output_type> result_of(Input... input) {
    return Result<output_type>(operator()(input...));
  }

  Result<output_type> result_of(disable_if_is_t<Input, std::string>... input) {
    return Result<output_type>(operator()(deserialize<Input>(input)...));
  }

  int ensure(std::vector<Thunk<output_type>> thunks) const {
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