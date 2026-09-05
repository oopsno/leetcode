/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include <string>
#include <vector>
class Solution {
public:
  std::string longestCommonPrefix(std::vector<std::string> &strs) {
    if (strs.empty()) {
      return "";
    }
    size_t shortest = strs.front().size();
    for (const auto &s : strs) {
      shortest = std::min(s.size(), shortest);
    }
    int prefix = 0;
    bool stop = false;
    for (; prefix < shortest; ++prefix) {
      const char c = strs.front()[prefix];
      for (const auto &s : strs) {
        if (s[prefix] != c) {
          stop = true;
          break;
        }
      }
      if (stop) {
        break;
      }
    }
    return strs.front().substr(0, prefix);
  }
};
// @lc code=end
