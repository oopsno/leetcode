/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
#include <string>
#include <cstring>

class Solution {
public:
    bool isPalindrome(std::string s) const noexcept {
        // 此题将空字符串定义为有效的回文串
        if (s.size() < 2) {
            return true;
        }
        int left = 0, right = s.size() - 1;
        while (left < right) {
          if (not std::isalnum(s[left])) {
            left += 1;
          } else if (not std::isalnum(s[right])) {
            right -= 1;
          } else {
              if (std::tolower(s[left]) != std::tolower(s[right])) {
                  return false;
              }
              left += 1;
              right -= 1;
          }
        }
        return true;
    }
};
// @lc code=end

