/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

#include <algorithm>
#include <limits>

// @lc code=start
class Solution {
 public:
  bool isPalindrome(int x) const noexcept {
    if (x < 0) {
      return false;
    }
    if (x < 10) {
      return true;
    }
    int p = x, y = 0;
    while (p != 0 and y <= std::numeric_limits<int>::max() / 10) {
      const auto d = std::div(p, 10);
      y = y * 10 + d.rem;
      p = d.quot;
    }
    return x == y;
  }
};
// @lc code=end
