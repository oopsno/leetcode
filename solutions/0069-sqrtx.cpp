/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

#include <cmath>
// @lc code=start
class Solution {
 public:
  int mySqrt(int n) {
    // f(x)  = x^2 - n
    // f'(x) = 2x
    // g(x)  = x - f(x) / f'(x) = (x + n / x) / 2
    double x = 1., xi = -1.;
    while (true) {
      xi = (x + n / x) / 2;
      if (std::abs(xi - x) < 0.1) {
          break;
      }
      x = xi;
    }
    return std::floor(x);
  }
};
// @lc code=end
