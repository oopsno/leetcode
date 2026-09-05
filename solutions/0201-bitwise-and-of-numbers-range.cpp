/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与 / Bitwise AND of Numbers Range
 * Given two integers `left` and `right` that represent the range [left, right],
 * return the bitwise AND of all numbers in this range, inclusive.
 */

// @lc code=start
class Solution {
public:
  int rangeBitwiseAnd(int m, int n) {
    if (((~m) & n) > m) {
      return 0;
    } else {
      return m & n;
    }
  }
};
// @lc code=end

#include "leetcode/runner.h"
#include <doctest/doctest.h>

TEST_CASE("0201") {
  auto f = Runner(201, &Solution::rangeBitwiseAnd);
  REQUIRE_EQ(f(5, 6), 4);
  REQUIRE_EQ(f(0, 0), 0);
  REQUIRE_EQ(f(1, 2147483647), 0);
}
