/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
#include <array>
#include <bitset>
#include <nlohmann/json_fwd.hpp>
#include <vector>

class Solution {
private:
  struct region {
    int xmin, xmax, ymin, ymax;
  };

public:
  bool isValidSudoku(std::vector<std::vector<char>> &board) {
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
        const auto &r = region_limits[i * 3 + j];
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

#include <doctest/doctest.h>
#include <nlohmann/json.hpp>

static std::vector<std::vector<char>> convert(const std::string &literal) {
  std::vector<std::vector<std::string>> xs = nlohmann::json::parse(literal);
  std::vector<std::vector<char>> ys(xs.size());
  auto row_iter = ys.begin();
  for (const auto &row : xs) {
    for (const auto &col : row) {
      row_iter->push_back(col.front());
    }
    row_iter++;
  }
  return ys;
}

TEST_CASE("0036") {
  // clang-format off
  const std::string example_1 =
    R"([["5","3",".",".","7",".",".",".","."]
       ,["6",".",".","1","9","5",".",".","."]
       ,[".","9","8",".",".",".",".","6","."]
       ,["8",".",".",".","6",".",".",".","3"]
       ,["4",".",".","8",".","3",".",".","1"]
       ,["7",".",".",".","2",".",".",".","6"]
       ,[".","6",".",".",".",".","2","8","."]
       ,[".",".",".","4","1","9",".",".","5"]
       ,[".",".",".",".","8",".",".","7","9"]])";
  // clang-format on
  auto sudoku_1 = convert(example_1);
  REQUIRE(Solution().isValidSudoku(sudoku_1));

  // clang-format off
  const std::string example_2 =
    R"([["8","3",".",".","7",".",".",".","."]
       ,["6",".",".","1","9","5",".",".","."]
       ,[".","9","8",".",".",".",".","6","."]
       ,["8",".",".",".","6",".",".",".","3"]
       ,["4",".",".","8",".","3",".",".","1"]
       ,["7",".",".",".","2",".",".",".","6"]
       ,[".","6",".",".",".",".","2","8","."]
       ,[".",".",".","4","1","9",".",".","5"]
       ,[".",".",".",".","8",".",".","7","9"]])";
  // clang-format on
  auto sudoku_2 = convert(example_2);
  REQUIRE_FALSE(Solution().isValidSudoku(sudoku_2));
}