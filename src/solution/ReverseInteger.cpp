#include <cstdlib>

#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X7 {
#endif

class Solution {
 public:
  typedef long long int lli_t;
  int reverse(int x) {
    if (x == INT_MIN) {
      return 0;
    }
    if (x < 0) {
      return -reverse(-x);
    }
    lli_t reversed = reverse64(x);
    if (reversed > INT32_MAX) {
      return 0;
    } else {
      return int(reversed);
    }
  }
  int64_t reverse64(lli_t x) {
    lli_t y = 0;
    while (x != 0) {
      const auto r = std::div(x, 10LL);
      y = y * 10 + r.rem;
      x = r.quot;
    }
    return y;
  }
};

#if (defined(OFFLINE))
}
#endif