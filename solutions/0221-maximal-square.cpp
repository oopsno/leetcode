/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

#include <algorithm>
#include <vector>
// @lc code=start
class Solution {
 public:
  int maximalSquare(
      const std::vector<std::vector<char>>& matrix) const noexcept {
    if (matrix.empty() or matrix.front().empty()) {
      return 0;
    }
    const size_t height = matrix.size();
    const size_t width = matrix.front().size();
    std::vector<std::vector<int>> dp(height, std::vector<int>(width, 0));
    int length_of_size = 0;
    for (size_t y = 0; y < height; ++y) {
      for (size_t x = 0; x < width; ++x) {
        if (matrix[y][x] == '1') {
          if (y == 0 or x == 0) {
              dp[y][x] = 1;
          } else {
            const int left = dp[y][x - 1];
            const int top = dp[y - 1][x];
            const int corner = dp[y - 1][x - 1];
            dp[y][x] = std::min(top, std::min(left, corner)) + 1;
          }
          length_of_size = std::max(length_of_size, dp[y][x]);
        }
      }
    }
    return length_of_size * length_of_size;
  }
};
// @lc code=end
