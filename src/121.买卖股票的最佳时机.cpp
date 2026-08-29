/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

#include <deque>
#include <vector>

namespace rmq {
// @lc code=start
class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    std::deque<int> mono_stack;
    int maxProfit = 0;
    for (const int price : prices) {
      while (not mono_stack.empty() and mono_stack.back() > price) {
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
  int maxProfit(const std::vector<int> &prices) const noexcept {
    int maxProfit = 0;
    int cheapest = std::numeric_limits<int>::max();
    for (const int price : prices) {
      maxProfit = std::max(maxProfit, price - cheapest);
      cheapest = std::min(cheapest, price);
    }
    return maxProfit;
  }
};
// @lc code=end
} // namespace greedy

#include "quicktest.hpp"

int main() {
  auto endpoint = quicktest::EndPoint(&rmq::Solution::maxProfit);
  return endpoint.ensure({
    endpoint.result_of("[7,1,5,3,6,4]").should_be(5),
    endpoint.result_of("[7,6,4,3,1]").should_be(0)
  });
}
