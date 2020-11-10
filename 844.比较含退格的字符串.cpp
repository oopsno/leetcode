/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

#include <algorithm>
#include <string>
#include <tuple>

// @lc code=start
class Solution {
 private:
  static char next(const std::string &s, int &offset) noexcept {
    for (int sharps = 0; offset >= 0; offset -= 1) {
      const char current = s[offset];
      if (current == '#') {
        sharps += 1;
      } else if (sharps == 0) {
        offset -= 1;
        return current;
      } else {
        sharps -= 1;
      }
    }
    return 0;
  }

 public:
  bool backspaceCompare(const std::string &s,
                        const std::string &t) const noexcept {
    int lhs = s.size() - 1, rhs = t.size() - 1;
    while (lhs >= 0 and rhs >= 0) {
      if (next(s, lhs) != next(t, rhs)) {
        return false;
      }
    }
    return (lhs < 0 or next(s, lhs) == 0) 
       and (rhs < 0 or next(t, rhs) == 0);
  }
};
// @lc code=end