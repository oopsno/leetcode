/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <tuple>
#include <vector>

struct Manacher {
  std::vector<int> p;
  std::string s;

  Manacher(const std::string &origin)
      : p(2 * origin.size() + 1, 0), s(2 * origin.size() + 1, '#') {
    for (auto i = 0; i < origin.size(); ++i) {
      s[2 * i + 1] = origin[i];
    }
  }

  int expand(int previous, int center) {
    const int length = p[previous];
    int skip = 0;
    if (previous + length > center) {
      skip = std::min(p[2 * previous - center], previous + length - center);
    }
    int left = center - skip - 1;
    int right = center + skip + 1;
    while (left >= 0 and right < s.size() and s[left] == s[right]) {
      left -= 1;
      right += 1;
    }
    p[center] = right - center - 1;
    return right;
  }

  std::vector<int> &eval() noexcept {
    int previous = 0, length = p[0];
    for (int i = 0; i < s.size(); ++i) {
      int right = expand(previous, i);
      if (right > previous + length) {
        previous = i;
        length = p[i];
      }
    }
    return p;
  }
};

class Solution {
public:
  std::string longestPalindrome(const std::string s) {
    std::vector<int> p = std::move(Manacher(s).eval());
    auto i = std::distance(p.cbegin(), std::max_element(p.cbegin(), p.cend()));
    int length = p[i];
    int start = (i - length) / 2;
    return s.substr(start, length);
  }
};
// @lc code=end