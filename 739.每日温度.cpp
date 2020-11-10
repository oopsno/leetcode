/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
#include <stack>
#include <vector>
class Solution {
public:
  std::vector<int> dailyTemperatures(std::vector<int> &T) {
    std::stack<int> s;
    std::vector<int> result(T.size(), 0);
    for (int i = 0; i < T.size(); ++i) {
      const int t = T[i];
      while (not s.empty() and T[s.top()] < t) {
        result[s.top()] = i - s.top();
        s.pop();
      }
      s.push(i);
    }
    return result;
  }
};
// @lc code=end
