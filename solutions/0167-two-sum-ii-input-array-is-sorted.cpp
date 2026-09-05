/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

#include <iterator>
#include <vector>

namespace {
// @lc code=start
class Solution {
public:
  std::vector<int> twoSum(const std::vector<int> &xs, const int target) {
    auto left = xs.cbegin();
    auto right = std::prev(xs.cend());
    while (true) {
      const int current = *left + *right;
      if (current == target) {
        break;
      } else if (current < target) {
        ++left;
      } else {
        --right;
      }
    }
    int index_1 = std::distance(xs.begin(), left);
    int index_2 = std::distance(xs.begin(), right);
    return {index_1 + 1, index_2 + 1};
  }
};
// @lc code=end
} // namespace

#include "leetcode/runner.h"
#include <doctest/doctest.h>

TEST_CASE("0167") {
  auto f = Runner(167, &Solution::twoSum);
  REQUIRE_EQ(f({2, 7, 11, 15}, 9), std::vector{1, 2});
  REQUIRE_EQ(f({2, 3, 4}, 6), std::vector{1, 3});
  REQUIRE_EQ(f({-1, 0}, -1), std::vector{1, 2});
}