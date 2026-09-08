/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */

// @lc code=start
#include <limits>
#include <vector>

namespace {
class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    if (prices.size() <= 2) {
      return 0;
    }
    // 第 i 天结束后持有现金或股票的最大收益.
    // 加入冷冻期之后, 每天交易结束后有 3 种可能
    // 1. 买入, 持有股票, 最大收益: hold[i] = max(hold[i - 1], cash[i - 1] - p)
    // 2. 卖出, 进入冷静期, 最大收益:   cool[i] = hold[i - 1] + p
    // 3. 等待, 冷静期结束, 最大收益:   cash[i] = max(cash[i - 1], cool[i - 1])
    int hold = -prices.front(); // 第 0 天持有，只可能是第 0 天买入
    int cash = 0, cool = 0;
    for (const int p : prices) {
      const int hold_next = std::max(hold, cash - p);
      const int cool_next = hold + p;
      const int cash_next = std::max(cash, cool);
      hold = hold_next;
      cool = cool_next;
      cash = cash_next;
    }
    return std::max(cool, cash);
  }
};
// @lc code=end
}

#include "leetcode/runner.h"
#include <doctest/doctest.h>

TEST_CASE("0309") {
  auto f = Runner{309, &Solution::maxProfit};
  std::vector<int> prices1 = {1, 2, 3, 0, 2};
  REQUIRE_EQ(f(prices1), 3);
  std::vector<int> prices2 = {1};
  REQUIRE_EQ(f(prices2), 0);
}
