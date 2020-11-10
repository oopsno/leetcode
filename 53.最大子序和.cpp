/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
#include <vector>

class Solution {
public:
  int maxSubArray(const std::vector<int> &nums) const noexcept {
    std::vector<int> m(nums.size());
    m[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      m[i] = std::max(m[i - 1] + nums[i], nums[i]);
    }
    int maximum = m[0];
    for (int e : m) {
        maximum = std::max(e, maximum);
    }
    return maximum;
  }
};
// @lc code=end
