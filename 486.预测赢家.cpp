/*
 * @lc app=leetcode.cn id=486 lang=cpp
 *
 * [486] 预测赢家
 */

// @lc code=start
#include <iostream>
#include <tuple>
#include <vector>
class Solution {
public:
  bool PredictTheWinner(std::vector<int> &nums) {
    // 1 或 2 个数时一定是先手赢
    if (nums.size() <= 2) {
      return true;
    }
    auto m = std::vector<std::vector<int>>(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
      m[i].resize(nums.size());
      m[i][i] = nums[i];
    }
    for (int i = nums.size() - 1; i >= 0; --i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        m[i][j] = std::max(nums[i] - m[i + 1][j], nums[j] - m[i][j - 1]);
      }
    }
    return m.front().back() >= 0;
  }
};
// @lc code=end