/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 *
 * You are given an integer array `prices` where `prices[i]` is the price of a given stock on the ith day.
 * Find the maximum profit you can achieve. You may complete at most two transactions.
 * Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
 */

// @lc code=start
#include <limits>
#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    // 第 i 天结束后, 至多交易 k 次时持有现金或股票的最大收益
    // hold[i][k] = max(hold[i-1][k], cash[i-1][k-1] - prices[i])
    // cash[i][k] = max(cash[i-1][k], hold[i-1][k]   + prices[i])
    // 至多交易 2 次化
    // 第一次买入: hold1[i] = max(hold1[i-1], 0        - prices[i])
    // 第一次卖出: cash1[i] = max(cash1[i-1], hold1[i] + prices[i])
    // 第二次买入: hold2[i] = max(hold2[i-1], cash1[i] - prices[i])
    // 第二次卖出: cash2[i] = max(cash2[i-1], hold2[i] + prices[i])
    // 显然只需要 4 个变量完成推导
    constexpr int NEG_INF = std::numeric_limits<int>::min();
    int cash1 = 0, cash2 = 0, hold1 = NEG_INF, hold2 = NEG_INF;
    for (const int p : prices) {
      hold1 = std::max(hold1, -p);
      cash1 = std::max(cash1, hold1 + p);
      hold2 = std::max(hold2, cash1 - p);
      cash2 = std::max(cash2, hold2 + p);
    }
    return cash2;
  }
};
// @lc code=end

#include "leetcode/runner.h"
#include <doctest/doctest.h>

TEST_CASE("0123") {
  auto f = Runner{123, &Solution::maxProfit};
  std::vector<int> prices1 = {3, 3, 5, 0, 0, 3, 1, 4};
  REQUIRE_EQ(f(prices1), 6);
  std::vector<int> prices2 = {1, 2, 3, 4, 5};
  REQUIRE_EQ(f(prices2), 4);
  std::vector<int> prices3 = {7, 6, 4, 3, 1};
  REQUIRE_EQ(f(prices3), 0);
  std::vector<int> prices4 = {1};
  REQUIRE_EQ(f(prices4), 0);
}
