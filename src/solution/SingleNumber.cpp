#include <vector>

#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X136 {
#endif

class Solution {
 public:
  int singleNumber(std::vector<int> &nums) {
    int single = 0;
    for (int num : nums) {
      single ^= num;
    }
    return single;
  }
};

#if (defined(OFFLINE))
}
#endif