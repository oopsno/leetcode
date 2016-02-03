#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X96 {
#endif

template<int c>
struct ConstInt {
  const static int value = c;
};

template<template<int> class Tpl, int limit, int i = 1, int j = limit, uint64_t current = 0>
struct Prod {
  const static int value = Prod<Tpl, limit - 1, i + 1, j - 1, Tpl<i>::value * Tpl<j>::value + current>::value;
};

template<template<int> class Tpl, int i, int j, uint64_t current>
struct Prod<Tpl, 0, i, j, current>: ConstInt<current> {
};

template<int n>
struct UBST {
  const static int value = 2 * UBST<n - 1>::value + Prod<::X96::UBST, n - 2>::value;
};

template<>
struct UBST<0>: ConstInt<0> { };

template<>
struct UBST<1>: ConstInt<1> { };

template<int... args>
struct ConstIntArray {
  static const int array[sizeof...(args)];
};

template<int... args>
const int ConstIntArray<args...>::array[sizeof...(args)] = {args...};

template<int N, int i, template<int> class F, int... args>
struct GenerateArrayTplImpl {
  typedef typename GenerateArrayTplImpl<N - 1, i + 1, F, args..., F<i>::value>::result result;
};

template<int i, template<int> class F, int... args>
struct GenerateArrayTplImpl<0, i, F, args...> {
  typedef ConstIntArray<F<0>::value, args...> result;
};

template<int N, template<int> class F>
struct GenerateArrayTpl {
  typedef typename GenerateArrayTplImpl<N - 1, 1, F>::result result;
};

typedef GenerateArrayTpl<20, UBST>::result cheatsheet_t;

class Solution {
 public:
  int numTrees(int n) {
    return n < 0 ? 0 : cheatsheet_t::array[n];
  }
};

#if (defined(OFFLINE))
}
#endif