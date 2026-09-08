/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 *
 * You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
 * Find the maximum profit you can achieve.
 * You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
 * Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
 */

// @lc code=start
#include <limits>
#include <vector>
namespace {
class Solution {
public:
  int maxProfit(int k, std::vector<int> &prices) {
    if (prices.size() <= k) {
      return 0;
    }
    // 第 i 天结束后, 至多交易 k 次时持有现金或股票的最大收益
    // hold[i][k] = max(hold[i-1][k], cash[i-1][k-1] - prices[i])
    // cash[i][k] = max(cash[i-1][k], hold[i-1][k]   + prices[i])
    // 这次需要 2k 个变量完成推导
    constexpr int NEG_INF = std::numeric_limits<int>::min();
    auto cash = std::vector<int>(k, 0);
    auto hold = std::vector<int>(k, NEG_INF);
    for (const int p : prices) {
      hold[0] = std::max(hold[0], -p);
      cash[0] = std::max(cash[0], hold[0] + p);
      for (int j = 1; j < k; ++j) {
        hold[j] = std::max(hold[j], cash[j - 1] - p);
        cash[j] = std::max(cash[j], hold[j] + p);
      }
    }
    return cash.back();
  }
};
} // namespace
// @lc code=end

#include "leetcode/runner.h"
#include <doctest/doctest.h>

TEST_CASE("0188") {
  auto f = Runner{188, &Solution::maxProfit};
  std::vector<int> prices1 = {2, 4, 1};
  REQUIRE_EQ(f(2, prices1), 2);
  std::vector<int> prices2 = {3, 2, 6, 5, 0, 3};
  REQUIRE_EQ(f(2, prices2), 7);
}
