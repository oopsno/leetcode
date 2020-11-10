/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include <algorithm>
#include <limits>
#include <vector>

// @lc code=start
class Solution {
 public:
  int maxProfit(const std::vector<int>& prices) const noexcept {
    // 最大利润
    int profit = 0;
    //历史最低价
    int cheapest = std::numeric_limits<int>::max();
    for (const int price : prices) {
      profit = std::max(profit, price - cheapest);
      cheapest = std::min(cheapest, price);
    }
    return profit;
  }
};
// @lc code=end
