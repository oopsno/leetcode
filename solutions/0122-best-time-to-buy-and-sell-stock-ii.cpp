/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
#include <vector>

class Solution {
public:
  int maxProfit(const std::vector<int> &prices) const noexcept {
    if (prices.size() <= 1) {
      return 0;
    }
    int profit = 0;
    int i = 0;
    while (1 + i < prices.size() and prices[i] > prices[i + 1]) {
      i += 1;
    }
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

#include <doctest/doctest.h>

TEST_CASE("0122") {
  REQUIRE_EQ(Solution().maxProfit({7, 1, 5, 3, 6, 4}), 7);
  REQUIRE_EQ(Solution().maxProfit({1, 2, 3, 4, 5}), 4);
  REQUIRE_EQ(Solution().maxProfit({7, 6, 4, 3, 1}), 0);
}
