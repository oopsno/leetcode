/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */
#include <string>
#include <vector>
#include <unordered_map>

// @lc code=start
class Solution {
 public:
  std::vector<int> partitionLabels(std::string S) {
      std::unordered_map<char, int> m;
      std::vector<int> result;
      for (int i = 0; i < S.size(); ++i) {
          m[S[i]] = i;
      }
      int begin = 0, left = 0, right = m[S[0]];
      while (left < S.size() and right < S.size()) {
          const char c = S[left];
          const int end = m[c];
          if (end > right) {
              right = end;
              left += 1;
          } else if (left == right) {
              result.emplace_back(right - begin + 1);
              begin = left = right + 1;
              right = m[S[left]];
          } else {
            left += 1;
          }
      }
      return result;
  }
};
// @lc code=end
