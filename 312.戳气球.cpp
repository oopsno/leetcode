/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

// @lc code=start
#include <vector>

class Solution {
public:
  int maxCoins(std::vector<int> &nums) const noexcept {
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    std::vector<std::vector<int>> m(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
      m[i].resize(nums.size());
      std::fill(m[i].begin(), m[i].end(), 0);
    }
    for (int i = nums.size() - 1; i >= 0; --i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        for (int k = i + 1; k < j; ++k) {
          m[i][j] = std::max(m[i][k] + nums[i] * nums[k] * nums[j] + m[k][j],
                             m[i][j]);
        }
      }
    }
    return m.front().back();
  }
};
// @lc code=end