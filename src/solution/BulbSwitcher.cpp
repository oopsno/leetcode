#include <cmath>
#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X319 {
#endif

class Solution {
 public:
  int bulbSwitch(int n) {
    return int(sqrt(n));
  }
};

#if (defined(OFFLINE))
}
#endif