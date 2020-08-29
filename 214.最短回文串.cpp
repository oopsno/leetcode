/*
 * @lc app=leetcode.cn id=214 lang=cpp
 *
 * [214] 最短回文串
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <vector>

struct Manacher {
  std::string s;
  std::vector<int> p;

  Manacher(const std::string &raw)
      : s(2 * raw.size() + 1, '#'), p(2 * raw.size() + 1, 0) {
    for (auto i = 0; i < raw.size(); ++i) {
      s[2 * i + 1] = raw[i];
    }
  }

  std::tuple<int, int> expand(int j, int i) {
    const int lenght = p[j];
    int skip = 0;
    if (j + lenght > i) {
      skip = std::min(p[2 * j - i], j + lenght - i);
    }
    int left = i - skip - 1;
    int right = i + skip + 1;
    while (0 <= left and right < s.size() and s[left] == s[right]) {
      left -= 1;
      right += 1;
    }
    p[i] = right - i - 1;
    return {left + 1, right - 1};
  }

  int eval() noexcept {
    int maximum_pos = 0, maximum_length = p[0];
    int prefix_length = 0;
    for (int i = 1; i <= p.size() / 2; ++i) {
        const auto [left, right] = expand(maximum_pos, i);
        if (right > maximum_pos + maximum_length) {
            maximum_pos = i;
            maximum_length = p[i];
        }
        if (left == 0) {
            prefix_length = std::max(prefix_length, right - left + 1);
        }
    }
    return prefix_length / 2;
  }
};

class Solution {
public:
  std::string shortestPalindrome(const std::string s) const noexcept {
      // 计算从 s[0] 开始的最长回文串的长度
      int prefix_length = Manacher(s).eval();
      // 如果 s 本身就是回文的，直接返回
      if (prefix_length == s.size()) {
          return s;
      }
      // 反转后缀以构造前缀
      auto prefix =  s.substr(prefix_length, s.size() - prefix_length);
      std::reverse(prefix.begin(), prefix.end());
      return prefix + s;
  }
};
// @lc code=end