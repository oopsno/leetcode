/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

#include <deque>
#include <limits>
#include <vector>

namespace mono_stack {
// @lc code=start
class Solution {
public:
  int maxProfit(const std::vector<int> &prices) {
    std::deque<int> mono_stack;
    int maxProfit = 0;
    for (const int price : prices) {
      while (!mono_stack.empty() && mono_stack.back() > price) {
        mono_stack.pop_back();
      }
      mono_stack.push_back(price);
      if (mono_stack.size() >= 2) {
        maxProfit = std::max(maxProfit, mono_stack.back() - mono_stack.front());
      }
    }
    return maxProfit;
  }
};
// @lc code=end
} // namespace rmq

namespace greedy {
// @lc code=start
class Solution {
public:
  int maxProfit(const std::vector<int> &prices) {
    // 只有 3 种可能: 空仓 -买入-> 持有; 持有 -卖出-> 空仓; 不交易
    // cash[i] = max(cash[i - 1], hold[i - 1] + prices[i]) // 不交易或者卖出
    // hold[i] = max(hold[i - 1], cash[i - i] - prices[i]) // 不交易或者买入
    // 只交易 1 次, 化简到
    // cash = max(cash, hold + prices[i]);
    // hold = max(hold, cash - prices[i]); where cash=0
    int hold = std::numeric_limits<int>::min();
    int cash = 0;
    for (const int price : prices) {
      cash = std::max(cash, hold + price);
      hold = std::max(hold, -price);
    }
    return cash;
  }
};
// @lc code=end
} // namespace greedy

#include "leetcode/runner.h"
#include <doctest/doctest.h>

TEST_CASE_TEMPLATE("0121", Solution, mono_stack::Solution, greedy::Solution) {
  auto f = Runner{121, &Solution::maxProfit};
  REQUIRE_EQ(f({7, 1, 5, 3, 6, 4}), 5);
  REQUIRE_EQ(f({7, 6, 4, 3, 1}), 0);
}