/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

#include <fmt/core.h>
#include <fmt/ranges.h>

#include <iostream>

// @lc code=start
#include <algorithm>
#include <array>
#include <bitset>
#include <functional>
#include <tuple>
#include <vector>

template <typename T>
using mat_t = std::vector<std::vector<T>>;

struct region {
  int xmin, xmax, ymin, ymax;
};

struct puzzle_t {
  std::array<std::bitset<9>, 9> rows;
  std::array<std::bitset<9>, 9> cols;
  std::array<std::array<std::bitset<9>, 3>, 3> regions;

  puzzle_t(const mat_t<char>& m) {
    for (int row = 0; row < 9; ++row) {
      for (int col = 0; col < 9; ++col) {
        const auto current = m[row][col];
        if (current != '.') {
          rows[row].set(current - '1');
          cols[col].set(current - '1');
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
            const auto current = m[row][col];
            if (current != '.') {
              regions[i][j].set(current - '1');
            }
          }
        }
      }
    }
  }

  bool is_valid() const noexcept {
    constexpr auto pred = [](const std::bitset<9>& bits) { return bits.all(); };
    return std::all_of(rows.cbegin(), rows.cend(), pred);
    std::all_of(cols.cbegin(), cols.cend(), pred);
    std::all_of(regions.cbegin(), regions.cend(), [&pred](const auto& rs) {
      return std::all_of(rs.cbegin(), rs.cend(), pred);
    });
  }

  std::bitset<9> candidates(const int row, const int col) noexcept {
    return rows[row] & cols[col] & regions[row / 3][col / 3];
  }

  void set(int row, int col, int value) noexcept {
    rows[row].set(value - 1);
    cols[col].set(value - 1);
    regions[row / 3][col / 3].set(value - 1);
  }

  void reset(int row, int col, int value) noexcept {
    rows[row].reset(value - 1);
    cols[col].reset(value - 1);
    regions[row / 3][col / 3].reset(value - 1);
  }

  bool allow(int row, int col, int value) const noexcept {
    return not rows[row].test(value - 1) and not cols[col].test(value - 1) and
           not regions[row / 3][col / 3].test(value - 1);
  }

  bool compress(mat_t<char>& board) noexcept {
    bool modified = false;
    for (int row = 0; row < 9; ++row) {
      for (int col = 0; col < 9; ++col) {
        if (board[row][col] != '.') {
          continue;
        }
        auto cross = rows[row] | cols[col] | regions[row / 3][col / 3];
        if (cross.count() == 8) {
          for (int candidate = 0; candidate < 9; ++candidate) {
            if (not cross.test(candidate)) {
              board[row][col] = candidate + '1';
              set(row, col, candidate + 1);
              modified = true;
              break;
            }
          }
        }
      }
    }
    return modified;
  }
};

class Solution {
 private:
  static std::vector<std::tuple<int, int>> find_unknonws(
      const mat_t<char>& board) noexcept {
    std::vector<std::tuple<int, int>> unknowns;
    for (int row = 0; row < 9; ++row) {
      for (int col = 0; col < 9; ++col) {
        if (board[row][col] == '.') {
          unknowns.emplace_back(row, col);
        }
      }
    }
    return unknowns;
  }

  static bool solveSudoku(mat_t<char>& board, puzzle_t& puzzle,
                          const std::vector<std::tuple<int, int>>& unknowns,
                          const int step = 0) noexcept {
    const bool is_last = step == unknowns.size() - 1;
    const auto [row, col] = unknowns[step];
    for (int candidate = 1; candidate <= 9; ++candidate) {
      if (puzzle.allow(row, col, candidate)) {
        puzzle.set(row, col, candidate);
        board[row][col] = '0' + candidate;
        bool success = false;
        if (is_last) {
          success = puzzle.is_valid();
        } else {
          success = solveSudoku(board, puzzle, unknowns, step + 1);
        }
        if (success) {
          return success;
        }
        puzzle.reset(row, col, candidate);
      }
    }
    return false;
  }

 public:
  void solveSudoku(std::vector<std::vector<char>>& board) noexcept {
    puzzle_t puzzle(board);
    // 填写所有确定解以缩小搜索范围
    while (puzzle.compress(board))
      ;
    // 确定所有未知数位置
    const auto unknowns = find_unknonws(board);
    // 启动搜索
    if (not unknowns.empty()) {
      solveSudoku(board, puzzle, unknowns);
    }
  }
};
// @lc code=end

#include <iostream>

int main() {
  Solution s;
  mat_t<char> puzzle{{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                     {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                     {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                     {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                     {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                     {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                     {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                     {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                     {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  s.solveSudoku(puzzle);
  for (auto r : puzzle) {
    std::cout << fmt::format("{}", r) << std::endl;
  }

  puzzle = {{'.', '.', '.', '2', '.', '.', '.', '6', '3'},
            {'3', '.', '.', '.', '.', '5', '4', '.', '1'},
            {'.', '.', '1', '.', '.', '3', '9', '8', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '9', '.'},
            {'.', '.', '.', '5', '3', '8', '.', '.', '.'},
            {'.', '3', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '2', '6', '3', '.', '.', '5', '.', '.'},
            {'5', '.', '3', '7', '.', '.', '.', '.', '8'},
            {'4', '7', '.', '.', '.', '1', '.', '.', '.'}};
  std::cout << fmt::format("std::bitset<81> = {}", sizeof(std::bitset<81>))
            << std::endl
            << fmt::format("puzzle_t = {}", sizeof(puzzle_t)) << std::endl;
  s.solveSudoku(puzzle);
  for (auto r : puzzle) {
    std::cout << fmt::format("{}", r) << std::endl;
  }
  return 0;
}