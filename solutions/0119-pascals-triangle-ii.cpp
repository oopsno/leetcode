/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
#include <vector>
class Solution {
public:
  std::vector<int> getRow(const int rowIndex) const noexcept {
    auto c = std::vector<int>(rowIndex + 1, 1);
    for (int n = 2; n <= rowIndex; ++n) {
      for (int m = n - 1; m > 0; --m) {
        c[m] += c[m - 1];
      }
    }
    return c;
  }
};
// @lc code=end
