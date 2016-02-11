#include <algorithm>

#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X326 {
#endif

template<typename T, T... args>
struct ConstArray {
  const static T array[sizeof...(args)];
};

template<typename T, T... args>
const T ConstArray<T, args...>::array[sizeof...(args)] = {args...};

template<int exp>
struct exp3 {
  const static int value = exp3<exp - 1>::value * 3;
};

template<>
struct exp3<0> {
  const static int value = 1;
};

template<int current, int max, int... args>
struct po3s_impl {
  typedef typename po3s_impl<current - 1, max, exp3<current>::value, args...>::type type;
};

template<int max, int... args>
struct po3s_impl<0, max, args...> {
  typedef ConstArray<int, exp3<0>::value, args...> type;
};

template<int n>
struct po3s {
  typedef typename po3s_impl<n, n>::type type;
};

template<int e = 0>
inline bool ispo3(int n) {
  return n == exp3<e>::value or ispo3<e + 1>(n);
}

template<>
inline bool ispo3<19>(int n) {
  return n == exp3<19>::value;
}

const static int *power_of_three = po3s<19>::type::array;
const static int *begin = power_of_three;
const static int *end = power_of_three + 20;

class Solution {
 public:
  static const inline bool isPowerOfThree(int n) {
    return std::binary_search(begin, end, n);
  }
};

#if (defined(OFFLINE))
}
#endif