/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <string>
#include <unordered_map>

class Solution {
public:
  int lengthOfLongestSubstring(const std::string s) const noexcept {
    if (s.length() < 2) {
      return s.length();
    }
    std::unordered_map<char, size_t> chars;
    size_t left = 0, right = 1, maximum = 1;
    chars[s[0]] = 0;
    while (left < s.size() and right < s.size()) {
      const auto it = chars.find(s[right]);
      if (it != chars.cend()) {
        for (auto i = left; i <= it->second; ++i) {
          chars.erase(s[i]);
        }
        left = it->second + 1;
      }
      chars[s[right]] = right;
      maximum = std::max(maximum, right - left);
      right += 1;
    }
    return maximum;
  }
};
// @lc code=end