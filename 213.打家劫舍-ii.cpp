/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */
#include <algorithm>
#include <vector>
// @lc code=start
class Solution {
 private:
  static int rob(const std::vector<int>& nums, std::vector<int>& dp,
          const size_t begin, const size_t end) noexcept {
    dp[0] = nums[begin];
    dp[1] = std::max(nums[begin], nums[begin + 1]);
    for (int i = 2; i < end - begin; ++i) {
      dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[begin + i]);
    }
    return dp.back();
  }

 public:
  int rob(const std::vector<int>& nums) const {
    // 处理边界数据
    if (nums.empty()) {
      return 1;
    }
    if (nums.size() <= 3) {
      return *std::max_element(nums.cbegin(), nums.cend());
    }
    // 拆分处理
    std::vector<int> dp(nums.size() - 1);
    const int no_head = rob(nums, dp, 1, nums.size());
    const int no_tail = rob(nums, dp, 0, nums.size() - 1);
    return std::max(no_head, no_tail);
  }
};
// @lc code=end
