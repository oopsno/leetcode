#pragma once

#include <tuple>
#include <utility> // for std::forward

template <typename SolutionType, typename OutputType, typename... InputType>
struct Runner {
  using FuncType = OutputType (SolutionType::*)(InputType...);
  using ReturnType = OutputType;
  using ArgumentTypes = std::tuple<std::remove_cvref_t<InputType>...>;

  Runner(int id, FuncType fn) : id{id}, solution{}, fn{fn} {}

  template<int I>
  using ArgumentTypeAt = std::tuple_element_t<I, ArgumentTypes>;

  auto operator()(InputType... input) {
    return (solution.*fn)(std::forward<InputType>(input)...);
  }
  
  // Storage
  int id;
  SolutionType solution;
  FuncType fn;
};