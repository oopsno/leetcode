/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

#include <algorithm>
#include <string>
#include <vector>
#include <numeric>

// @lc code=start

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
  int countSubstrings(const std::string s) const noexcept {
      const auto p = Manacher(s).eval();
      return std::accumulate(p.cbegin(), p.cend(), 0, [](int sum, int current) {
          return sum + (current + 1) / 2;
      });
  }
};
// @lc code=end
