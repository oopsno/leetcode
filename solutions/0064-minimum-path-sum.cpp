/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */
#include <vector>

namespace {
// @lc code=start

template <typename Element> struct matrix2d {
  matrix2d(size_t width, size_t height)
      : width(width), height(height), data(new Element[width * height]) {}

  matrix2d(size_t width, size_t height, Element initial)
      : matrix2d(width, height) {
    std::fill_n(data, width * height, initial);
  }

  ~matrix2d() { delete[] (data); }

  Element *data = nullptr;
  const size_t width, height;

  Element &at(size_t y, size_t x) { return data[y * width + x]; }

  const Element &at(size_t y, size_t x) const { return data[y * width + x]; }
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
        cache.at(y, x) =
            std::min(cache.at(y - 1, x), cache.at(y, x - 1)) + grid[y][x];
      }
    }
    return cache.at(m - 1, n - 1);
  }
};
// @lc code=end
} // namespace

#include "leetcode/runner.h"
#include <doctest/doctest.h>

TEST_CASE("0064") {
  auto f = Runner(64, &Solution::minPathSum);
  std::vector<std::vector<int>> example_1{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  std::vector<std::vector<int>> example_2{{1, 2, 3}, {4, 5, 6}};
  REQUIRE_EQ(f(example_1), 7);
  REQUIRE_EQ(f(example_2), 12);
}