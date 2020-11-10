/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */
#include <algorithm>
#include <vector>
// @lc code=start
class Solution {
 public:
  int maxProduct(const std::vector<int>& nums) const noexcept {
    if (nums.empty()) {
      return 0;
    }
    int fmax = nums.front(), fmin = nums.front(), result;
    for (int i = 1; i < nums.size(); ++i) {
      const int num = nums[i];
      const int lhs = fmax * num, rhs = fmin * num;
      fmax = std::max(lhs, std::max(rhs, num));
      fmin = std::min(lhs, std::min(rhs, num));
      result = std::max(fmin, fmax);
    }
    return result;
  }
};
// @lc code=end
