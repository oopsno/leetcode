/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
#include <vector>
#include <iostream>

template <typename Element> struct matrix2d {
  matrix2d(size_t width, size_t height)
      : width(width), height(height), data(new Element[width * height]) {}

  matrix2d(size_t width, size_t height, Element initial)
      : matrix2d(width, height) {
          std::fill_n(data, width * height, initial);
      }

  ~matrix2d() { delete[](data); }

  Element *data = nullptr;
  const size_t width, height;

  Element &at(size_t y, size_t x) { return data[y * width + x]; }

  const Element &at(size_t y, size_t x) const { return data[y * width + x]; }

  void debug() const noexcept {
#if (!defined(NDEBUG))
    for (auto y = 0; y < height; ++y) {
      for (auto x = 0; x < width; ++x) {
        std::cout << data[y * width + x] << " ";
      }
      std::cout << std::endl;
    }
#endif
  }
};

class Solution {
public:
  int minPathSum(const std::vector<std::vector<int>> &grid) noexcept {
      const size_t m = grid.size();
      const size_t n = grid.front().size();
      matrix2d<int> cache(n, m);
      cache.at(0, 0) = grid[0][0];
      for (size_t y = 1; y < m; ++y) {
        cache.at(y, 0) = grid[y][0] + cache.at(y - 1, 0);
      }
      for (size_t x = 1; x < n; ++x) {
        cache.at(0, x) = grid[0][x] + cache.at(0, x - 1);
      }
      for (size_t y = 1; y < m; ++y) {
        for (size_t x = 1; x < n; ++x) {
          cache.at(y, x) = std::min(cache.at(y - 1, x), cache.at(y, x - 1)) + grid[y][x];
        }
      }
      return cache.at(m - 1, n - 1);
  }
};
// @lc code=end

int main() { 
    Solution s;
    std::vector<std::vector<int>> grid{{1, 2}, {5, 6}, {1, 1}};
    std::cout << s.minPathSum(grid) << std::endl;
    return 0;
}