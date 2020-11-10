/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include <algorithm>
#include <vector>

// @lc code=start
class Solution {
 public:
  int rob(const std::vector<int>& nums) {
    // 处理边界数据
    if (nums.empty()) {
      return 0;
    }
    if (nums.size() <= 2) {
      return *std::max_element(nums.cbegin(), nums.cend());
    }
    std::vector<int> dp(nums.size());
    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); ++i) {
      dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp.back();
  }
};
// @lc code=end
