/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 */
#include <string>
#include <tuple>
// @lc code=start
class Solution {
 private:
  static std::tuple<char, int> next(const std::string &s, int &offset) {
    const char c = s[offset];
    int count = 0;
    for (; offset < s.size() and s[offset] == c; ++offset) {
      count += 1;
    }
    return {c, count};
  }

 public:
  bool isLongPressedName(const std::string &name, const std::string &typed) {
    int lhs = 0, rhs = 0;
    while (lhs < name.size() and rhs < typed.size()) {
      const auto [c, m] = next(name, lhs);
      const auto [t, n] = next(typed, rhs);
      if (c != t or m > n) {
        return false;
      }
    }
    return lhs == name.size() and rhs == typed.size();
  }
};
// @lc code=end
