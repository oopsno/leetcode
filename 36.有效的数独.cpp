/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

#include <iostream>

// @lc code=start
#include <array>
#include <bitset>
#include <tuple>
#include <vector>

template <typename T>
using mat_t = std::vector<std::vector<T>>;

class Solution {
 private:
  struct region {
    int xmin, xmax, ymin, ymax;
  };

 public:
  bool isValidSudoku(const mat_t<char>& board) {
    std::array<std::bitset<9>, 9> rows;
    std::array<std::bitset<9>, 9> cols;
    std::array<std::array<std::bitset<9>, 3>, 3> regions;
    for (int row = 0; row < 9; ++row) {
      for (int col = 0; col < 9; ++col) {
        const auto current = board[row][col];
        if (current != '.') {
          const int value = current - '1';
          if (rows[row].test(value)) {
            return false;
          }
          rows[row].set(value);
          if (cols[col].test(value)) {
            return false;
          }
          cols[col].set(value);
        }
      }
    }
    // clang-format off
    const std::vector<region> region_limits{
        {0, 3, 0, 3}, {3, 6, 0, 3}, {6, 9, 0, 3},
        {0, 3, 3, 6}, {3, 6, 3, 6}, {6, 9, 3, 6},
        {0, 3, 6, 9}, {3, 6, 6, 9}, {6, 9, 6, 9},
    };
    // clang-format on
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        const auto& r = region_limits[i * 3 + j];
        for (int row = r.ymin; row < r.ymax; ++row) {
          for (int col = r.xmin; col < r.xmax; ++col) {
            const auto current = board[row][col];
            if (current != '.') {
              const int value = current - '1';
              if (regions[i][j].test(value)) {
                return false;
              }
              regions[i][j].set(value);
            }
          }
        }
      }
    }
    return true;
  }
};
// @lc code=end

int main() {
  mat_t<char> m{{'.', '.', '.', '.', '5', '.', '.', '1', '.'},
                {'.', '4', '.', '3', '.', '.', '.', '.', '.'},
                {'.', '.', '.', '.', '.', '3', '.', '.', '1'},
                {'8', '.', '.', '.', '.', '.', '.', '2', '.'},
                {'.', '.', '2', '.', '7', '.', '.', '.', '.'},
                {'.', '1', '5', '.', '.', '.', '.', '.', '.'},
                {'.', '.', '.', '.', '.', '2', '.', '.', '.'},
                {'.', '2', '.', '9', '.', '.', '.', '.', '.'},
                {'.', '.', '4', '.', '.', '.', '.', '.', '.'}};
  std::cout << std::boolalpha << Solution().isValidSudoku(m) << std::endl;
}