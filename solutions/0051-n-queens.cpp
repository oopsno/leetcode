/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 */

#include <algorithm>
#include <string>
#include <vector>

namespace {
// @lc code=star

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
             std::vector<std::vector<std::string>> &solutions) const noexcept {
    if (y >= n) {
      solutions.push_back(current);
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
  std::vector<std::vector<std::string>> solveNQueens(int n) {
    if (n < 0 or n == 2 or n == 3) {
      return {};
    }
    if (n == 1) {
      return {{"Q"}};
    }
    std::vector<std::string> current(n, std::string(n, '.'));
    std::vector<std::vector<std::string>> solutions;
    solve(0, n, current, solutions);
    return solutions;
  }
};
// @lc code=end
} // namespace

#include "leetcode/runner.h"
#include <doctest/doctest.h>

TEST_CASE("0051") {
  auto f = Runner(51, &Solution::solveNQueens);
  using F = decltype(f)::ReturnType;
  REQUIRE_EQ(f(1), F{{"Q"}});
  REQUIRE_EQ(f(4), F{{".Q..", "...Q", "Q...", "..Q."},
                     {"..Q.", "Q...", "...Q", ".Q.."}});
}