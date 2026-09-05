/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
public:
  int addDigits(int num) {
    const auto rem = num % 9;
    if (num == 0) {
      return 0;
    }
    return rem > 0 ? rem : 9;
  }
};
// @lc code=end

#include <doctest/doctest.h>

TEST_CASE("0258") {
  REQUIRE_EQ(Solution().addDigits(38), 2);
  REQUIRE_EQ(Solution().addDigits(0), 0);
  REQUIRE_EQ(Solution().addDigits(9), 9);
  REQUIRE_EQ(Solution().addDigits(10), 1);
}
