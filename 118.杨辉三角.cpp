/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
#include <vector>
class Solution {
public:
  std::vector<std::vector<int>> generate(const int numRows) const noexcept {
    std::vector<std::vector<int>> c;
    for (auto n = 0; n < numRows; ++n) {
      c.emplace_back(1 + n, 1);
      for (auto m = 1; m < n; ++m) {
        c[n][m] = c[n - 1][m - 1] + c[n - 1][m];
      }
    }
    return c;
  }
};
// @lc code=end
