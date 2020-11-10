/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */
#include <algorithm>
#include <cmath>
#include <vector>

// @lc code=start
class Solution {
 public:
  int nthUglyNumber(int n) const noexcept {
    if (n < 1 or n > 1690) {
      return -1;  // 此时行为未定义
    }
    int two = 0, three = 0, five = 0;
    std::vector<int> u(size_t(n) + 1);
    u[0] = 1;
    for (int i = 1; i < n; ++i) {
      const int a = 2 * u[two];
      const int b = 3 * u[three];
      const int c = 5 * u[five];
      const int next = std::min(a, std::min(b, c));
      if (next == a) {
        two += 1;
      }
      if (next == b) {
        three += 1;
      }
      if (next == c) {
        five += 1;
      }
      u[i] = next;
    }
    return u[n - 1];
  }
};
// @lc code=end
