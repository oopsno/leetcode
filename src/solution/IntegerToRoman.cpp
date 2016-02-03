#include <array>
#include <string>
#include <numeric>
#include <functional>
#include <cstdlib>

#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X12 {
#endif

struct TableBase {
  typedef std::array<char, 5> element_t;
  typedef std::array<element_t, 10> aggregate_t;
};

template<const char u = 'I', const char q = 'V', const char d = 'X'>
struct ZeroToNine: TableBase {
  constexpr const static aggregate_t value = {
      element_t({}), {u}, {u, u}, {u, u, u}, {u, q}, {q}, {q, u}, {q, u, u}, {q, u, u, u}, {u, d}
  };
};

template<const char u = 'I'>
struct ZeroToThree: TableBase {
  constexpr const static aggregate_t value = {element_t({}), {u}, {u, u}, {u, u, u}};
};

constexpr const static std::array<ZeroToNine<>::aggregate_t, 4> TABLE = {
    ZeroToNine<'I', 'V', 'X'>::value, // 0-9
    ZeroToNine<'X', 'L', 'C'>::value, // 0-90
    ZeroToNine<'C', 'D', 'M'>::value, // 0-900
    ZeroToThree<'M'>::value
};

class Solution {
 public:
  std::string intToRoman(int num) {
    std::vector<std::string> bucket(4);
    for (int i = 0; i < 4; ++i) {
      const auto res = std::div(num, 10);
      num = res.quot;
      bucket[i] = TABLE[i][res.rem].data();
    }
    return std::accumulate(bucket.crbegin(), bucket.crend(), std::string(""), std::plus<std::string>());
  }

};

#if (defined(OFFLINE))
}
#endif