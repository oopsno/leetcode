#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X231 {
#endif

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) {
      return false;
    }
    int count = 0;
    for (int i = 0, flag = 1; i < sizeof(int)*8; i++, flag <<= 1) {
      if (n == flag) {
        count += 1;
      }
    }
    return count == 1;
  }
};

#if (defined(OFFLINE))
}
#endif