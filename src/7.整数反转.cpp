/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <numeric>

// @lc code=start
class Solution {
public:
  int reverse(int x) {
    const auto sig = std::signbit(x);
    x = std::abs(x);
    int64_t y = 0;
    while (x > 0) {
      const auto m = std::div(x, 10);
      y = y * 10 + m.rem;
      x = m.quot;
      if (y > std::numeric_limits<int>::max()) {
        return 0;
      }
    }
    const auto r = static_cast<int>(y);
    return sig ? -r : r;
  }
};
// @lc code=end
