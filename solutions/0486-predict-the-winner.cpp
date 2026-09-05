/*
 * @lc app=leetcode.cn id=486 lang=cpp
 *
 * [486] 预测赢家 / Predict the Winner
 */

// @lc code=start
#include <vector>
class Solution {
public:
  bool predictTheWinner(std::vector<int> &nums) {
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

#include "leetcode/runner.h"
#include <doctest/doctest.h>

TEST_CASE("0486") {
  auto f = Runner(486, &Solution::predictTheWinner);
  auto example_1 = std::vector{1, 5, 2};
  auto example_2 = std::vector{1, 5, 233, 7};
  REQUIRE_FALSE(f(example_1));
  REQUIRE(f(example_2));
}