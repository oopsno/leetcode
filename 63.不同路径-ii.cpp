/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
#include <vector>

class Solution {
public:
  int uniquePathsWithObstacles(
      std::vector<std::vector<int>> &obstacleGrid) const noexcept {
    if (obstacleGrid.empty() or obstacleGrid.front().front() == 1 or
        obstacleGrid.back().back() == 1) {
      return 0;
    }
    const int H = obstacleGrid.size();
    const int W = obstacleGrid.front().size();
    std::vector<std::vector<int>> m(H);
    for (int i = 0; i < obstacleGrid.size(); ++i) {
      m[i].resize(W);
    }
    m[0][0] = 1;
    for (int y = 0; y < H; ++y) {
      for (int x = 0; x < W; ++x) {
        if (obstacleGrid[y][x] == 1) {
          m[y][x] = 0;
        } else {
          if (x != 0 or y != 0) {
            m[y][x] = (y > 0 ? m[y - 1][x] : 0) + (x > 0 ? m[y][x - 1] : 0);
          } else {
            m[0][0] = 1;
          }
        }
      }
    }
    return m.back().back();
  }
};
// @lc code=end
