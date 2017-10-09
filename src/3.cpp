/**
 * 3. Longest Substring Without Repeating Characters
 */

#include <string>
#include <map>

class Solution {
 public:
  int lengthOfLongestSubstring(const std::string &s) {
    std::map<char, int> pos;
    int length = 0;
    for (auto left = 0, right = 0; right < s.size(); ++right) {
      const auto p = pos.find(s[right]);
      const auto c = s[right];
      if (p != pos.cend()) {
        left = std::max(left, pos[c] + 1);
      }
      pos[c] = right;
      length = std::max(length, right - left + 1);
    }
    return length;
  }
};

#include <gtest/gtest.h>

TEST(LongestSubstringWithoutRepeatingCharacters, abcabcbb) {
  auto s = "abcabcbb";
  ASSERT_EQ(Solution().lengthOfLongestSubstring(s), 3);
}

TEST(LongestSubstringWithoutRepeatingCharacters, bbbbb) {
  auto s = "bbbbb";
  ASSERT_EQ(Solution().lengthOfLongestSubstring(s), 1);
}

TEST(LongestSubstringWithoutRepeatingCharacters, pwwkew) {
  auto s = "pwwkew";
  ASSERT_EQ(Solution().lengthOfLongestSubstring(s), 3);
}
