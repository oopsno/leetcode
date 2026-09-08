/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 * On each day, you may decide to buy and/or sell the stock.
 * You can only hold at most one share of the stock at any time.
 * However, you can sell and buy the stock multiple times on the same day,
 * ensuring you never hold more than one share of the stock.
 */
#include <vector>

namespace {
// @lc code=start
class Solution {
public:
  int maxProfit(const std::vector<int> &prices) {
    if (prices.size() <= 1) {
      return 0;
    }
    // 第 i 天结束后持有现金或股票的最大收益
    // hold[i] = max(hold[i - 1], cash[i - 1] - prices[i]) // 不交易或者买入
    // cash[i] = max(cash[i - 1], hold[i - 1] + prices[i]) // 不交易或者卖出
    // 在任何一天收盘时，如果持有股票，等价于在“当天收盘价”买入，即
    // hold[i] = cash[i] - prices[i]
    // 题目的解最终只需要 cash[n], 代入得到
    // cash[i] = max(cash[i - 1], cash[i - 1] - prices[i - 1] + prices[i])
    //         = cash[i - 1] + max(0, prices[i] - prices[i - 1])
    int profit = 0;
    for (int i = 1; i < prices.size(); ++i) {
      profit += std::max(0, prices[i] - prices[i - 1]);
    }
    return profit;
  }
};
// @lc code=end
}

#include <doctest/doctest.h>
#include "leetcode/runner.h"

TEST_CASE("0122") {
  auto f = Runner(122, &Solution::maxProfit);
  REQUIRE_EQ(f({7, 1, 5, 3, 6, 4}), 7);
  REQUIRE_EQ(f({1, 2, 3, 4, 5}), 4);
  REQUIRE_EQ(f({7, 6, 4, 3, 1}), 0);
}
