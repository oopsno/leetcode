/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索 / Word Search
 */

#include <algorithm>
#include <array>
#include <vector>
// @lc code=start
namespace {
class Solution {
private:
  static void reset(std::vector<std::vector<int>> &used) {
    for (auto &row : used) {
      std::fill(row.begin(), row.end(), 0);
    }
  }

  static bool dfs(const std::vector<std::vector<char>> &board,
                  const std::string &word, std::vector<std::vector<int>> &used,
                  const int y, const int x, const int level) noexcept {
    // 注意：level 取值保证合法
    const char current = word[level];
    if (current == board[y][x]) {
      if (used[y][x] > 0) {
        return false;
      } else {
        used[y][x] = level + 1;
      }
    } else {
      return false;
    }
    // 匹配到达模式串末尾则匹配成功
    if (level == word.size() - 1) {
      return true;
    }
    // 搜索顺序：上 -> 下 -> 左 -> 右
    constexpr std::array directions{std::pair{-1, 0}, std::pair{1, 0},
                                    std::pair{0, -1}, std::pair{0, 1}};
    for (const auto p : directions) {
      const int next_y = y + p.first;
      const int next_x = x + p.second;
      if (0 <= next_y and next_y < board.size() and 0 <= next_x and
          next_x < board[y].size()) {
        if (dfs(board, word, used, next_y, next_x, level + 1)) {
          return true;
        }
      }
    }
    used[y][x] = 0;
    return false;
  }

public:
  bool exist(const std::vector<std::vector<char>> &board,
             const std::string word) {
    std::vector<std::vector<int>> used(
        board.size(), std::vector<int>(board.front().size(), -1));
    for (int y = 0; y < board.size(); ++y) {
      const auto &row = board[y];
      for (int x = 0; x < row.size(); ++x) {
        if (row[x] == word[0]) {
          reset(used);
          if (dfs(board, word, used, y, x, 0)) {
            return true;
          }
        }
      }
    }
    return false;
  }
};
// @lc code=end
} // namespace

#include <doctest/doctest.h>
#include <nlohmann/json.hpp>
#include "leetcode/runner.h"

TEST_CASE("0079") {
  auto f = Runner(79, &Solution::exist);
  using Board = decltype(f)::ArgumentTypeAt<0>;
  auto parse = [](const std::string& text){
    std::vector<std::vector<std::string>> obj = nlohmann::json::parse(text);
    std::vector<std::vector<char>> ret(obj.size());
    auto it = ret.begin();
    for (auto& row : obj) {
      for (auto& col : row) {
        it->push_back(col.front());
      }
      ++it;
    }
    return ret;
  };
  SUBCASE("example 1") {
    auto board = Board{{'A', 'B', 'C', 'E'}, {'S', 'F', 'E', 'S'}, {'A', 'D', 'E', 'E'}};
    const std::string word = "ABCESEEEFS";
    REQUIRE(f(board, word));
  }
  SUBCASE("example 2") {
    auto board = R"([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]])";
  }
}