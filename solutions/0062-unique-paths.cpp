/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
#include <array>
#include <memory>
#include <vector>

/**
 * 用于计算组合数的杨辉三角
 */
template <typename Int, size_t Maximum> struct yanghui_triangle {
  using matrix_t = std::array<std::array<Int, Maximum>, Maximum>;
  std::unique_ptr<matrix_t> matrix = nullptr;
  yanghui_triangle() : matrix{new matrix_t()} {
    matrix->operator[](0)[0] = 1;
    matrix->operator[](1)[0] = 1;
    matrix->operator[](1)[1] = 1;
    for (int level = 2; level < Maximum; ++level) {
      auto &current = matrix->operator[](level);
      auto &previous = matrix->operator[](level - 1);
      current[0] = 1;
      current[level] = 1;
      for (int i = 1; i < level; ++i) {
        current[i] = previous[i - 1] + previous[i];
      }
    }
  }

  Int at(int n, int m) const noexcept { return matrix->operator[](n)[m]; }
};

const static yanghui_triangle<uint32_t, 200> C;

class Solution {
public:
  int uniquePaths(int m, int n) const noexcept {
    return C.at(n + m - 2, std::min(n - 1, m - 1));
  }
};
// @lc code=end