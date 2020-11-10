/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
#include <array>
#include <unordered_map>
#include <vector>

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
    constexpr std::array<std::pair<int, int>, 4> directions{
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
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

#include <iostream>

int main() {
  const std::vector<std::vector<char>> board = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'E', 'S'}, {'A', 'D', 'E', 'E'}};

  const std::string word = "ABCESEEEFS";
  Solution s;
  std::cout << std::boolalpha << s.exist(board, word) << std::endl;
  return 0;
}