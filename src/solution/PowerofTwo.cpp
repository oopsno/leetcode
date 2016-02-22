#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X231 {
#endif

class Solution {
 public:
  static bool isPowerOfTwo(int64_t n) {
    return n > 0 and (INT_MAX + 1LL) % n == 0;
  }
};

#if (defined(OFFLINE))
}
#endif