#include <numeric>
#include <functional>

#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X238 {
#endif

class Solution {
 public:
  std::vector<int> productExceptSelf(std::vector<int> &nums) {
    const size_t len = nums.size();
    std::vector<int> result(len, 1);
    int temp = 1;
    for (int i = 1, j = 0; i < len; ++i, ++j) {
      result[i] *= temp *= nums[j];
    }
    temp = 1;
    for (int i = len - 2, j = len - 1; i >= 0; --i, --j) {
      result[i] *= temp *= nums[j];
    }
    return result;
  }
};

#if (defined(OFFLINE))
}
#endif