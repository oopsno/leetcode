/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找常用字符
 */

#include <algorithm>
#include <array>
#include <limits>
#include <string>
#include <vector>
// @lc code=start
class Solution {
 public:
  std::vector<std::string> commonChars(
      const std::vector<std::string>& A) const noexcept {
    std::vector<std::string> result;
    std::vector<std::array<int, 26>> m(A.size());
    for (int i = 0; i < A.size(); ++i) {
      for (const char c : A[i]) {
        m[i][c - 'a'] += 1;
      }
    }
    for (int i = 0; i < 26; ++i) {
      int count = std::numeric_limits<int>::max();
      for (int j = 0; j < A.size(); ++j) {
        count = std::min(count, m[j][i]);
      }
      while (count > 0) {
        result.emplace_back(1ULL, char(i + 'a'));
        count -= 1;
      }
    }
    return result;
  }
};
// @lc code=end
