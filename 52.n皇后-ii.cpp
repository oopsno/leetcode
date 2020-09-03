/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
private:
  bool acceptable_yet(const int y, const int x, const int n,
                      const std::vector<std::string> &current) const noexcept {
    for (int i = 0; i < y; ++i) {
      const int ul = x - y + i;
      const int ur = x + y - i;
      if (current[i][x] == 'Q') {
        return false;
      }
      if (0 <= ul and ul < n and current[i][ul] == 'Q') {
        return false;
      }
      if (0 <= ur and ur < n and current[i][ur] == 'Q') {
        return false;
      }
    }
    return true;
  }

  void solve(const int y, const int n, std::vector<std::string> &current,
             int &solutions) const noexcept {
    if (y >= n) {
      solutions += 1;
    } else {
      auto &row = current[y];
      for (int x = 0; x < n; ++x) {
        std::fill(row.begin(), row.end(), '.');
        row[x] = 'Q';
        if (acceptable_yet(y, x, n, current)) {
          solve(y + 1, n, current, solutions);
        }
      }
    }
  }

public:
  int totalNQueens(int n) const noexcept {
    if (n < 0 or n == 2 or n == 3) {
      return 0;
    }
    if (n == 1) {
      return 1;
    }
    std::vector<std::string> current(n, std::string(n, '.'));
    int solutions = 0;
    solve(0, n, current, solutions);
    return solutions;
  }
};
// @lc code=end
