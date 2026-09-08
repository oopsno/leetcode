/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
#include <limits>
#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int> &prices, int fee) {
    // 第 i 天结束后持有现金或股票的最大收益
    // hold[i] = max(hold[i - 1], cash[i - 1] - prices[i] - fee) // 不交易或者买入, 但不能第二天立刻买入
    // cash[i] = max(cash[i - 1], hold[i - 1] + prices[i]) // 不交易或者卖出
    int cash = 0, hold = std::numeric_limits<int>::min();
    for (const int p : prices) {
      const int hold_next = std::max(hold, cash - p - fee);
      cash = std::max(cash, hold + p);
      hold = hold_next;
    }
    return cash;
  }
};
// @lc code=end

#include "leetcode/runner.h"
#include <doctest/doctest.h>

TEST_CASE("0714") {
  auto f = Runner{714, &Solution::maxProfit};
  std::vector<int> prices1 = {1, 3, 2, 8, 4, 9};
  REQUIRE_EQ(f(prices1, 2), 8);
  std::vector<int> prices2 = {1, 3, 7, 5, 10, 3};
  REQUIRE_EQ(f(prices2, 3), 6);
}
