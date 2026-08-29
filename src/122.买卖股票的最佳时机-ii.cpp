/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
#include <algorithm>
#include <limits>
#include <vector>

// @lc code=start
class Solution {
 public:
  int maxProfit(const std::vector<int>& prices) const noexcept {
    if (prices.size() <= 1) {
      return 0;
    }
    // 最大利润
    int profit = 0;
    int i = 0;
    while (1 + i < prices.size() and prices[i] > prices[i + 1]) {
      i += 1;
    }
    // 持有成本
    int cost = prices[i];
    for (; i < prices.size(); ++i) {
      const int price = prices[i];
      if (price >= cost) {
        profit += price - cost;
      }
      cost = price;
    }
    return profit;
  }
};
// @lc code=end
