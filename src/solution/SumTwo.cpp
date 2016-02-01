#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X1 {
#endif

#include <vector>
#include <algorithm>

class Solution {
 public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    int temp;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[i] + nums[j] == target) {
          return {i + 1, j + 1};
        }
      }
    }
    return {0, 0};
  }
};

#if (defined(OFFLINE))
}
#endif