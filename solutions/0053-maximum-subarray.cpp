/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        std::vector<int> dp(nums.size());
        int result = dp[0] = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
            result = std::max(result, dp[i]);
        }
        return result; 
    }
};
// @lc code=end
