#pragma once

#include <functional>
#include <type_traits>

#include <fmt/core.h>
#include <fmt/ranges.h>
#include <fmt/color.h>

#include "leetcode.hpp"

namespace quicktest {

template <typename ValueType> struct Result {
  using value_type = ValueType;
  value_type actual;

  explicit Result(value_type &&actual) : actual(actual) {}

  template<typename=std::enable_if_t<not std::is_same_v<value_type, std::string>>>
  bool should_be(std::string expected_literal) {
    return should_be(leetcode::deserializer<std::remove_cvref_t<value_type>>()(expected_literal));
  }

  bool should_be(value_type &&expected) {
    if constexpr (std::is_integral_v<value_type>) {
      if (expected != actual) {
        fmt::print(fmt::fg(fmt::color::red), "❌ expected {}, got {}\n", expected, actual);
        return false;
      } else {
        fmt::print(fmt::fg(fmt::color::light_green), "🗸 expected {}, got {}\n", expected, actual);
      }
    }
    return false;
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

  output_type operator()(std::remove_cvref_t<Input>... input) { return (solution.*fn)(input...); }

  template <typename T>
  using literal_t = std::enable_if_t<not std::is_same_v<T, std::string>, std::string>;

  output_type from_literal(literal_t<Input>... input) {
    return operator()(leetcode::deserializer<std::remove_cvref_t<Input>>()(input)...);
  }

  Result<output_type> result_of(Input... input) {
    return Result<output_type>(operator()(input...));
  }

  Result<output_type> result_of(literal_t<Input>... input) {
    return Result<output_type>(operator()(leetcode::deserializer<std::remove_cvref_t<Input>>()(input)...));
  }
};

} // namespace quicktest