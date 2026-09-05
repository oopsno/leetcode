/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(const std::vector<int> &nums, const int target) {
    std::unordered_map<int, int> mapping;
    for (int i = 0; i < nums.size(); ++i) {
      const int num = nums[i];
      const int another = target - num;
      const auto it = mapping.find(num);
      if (it == mapping.cend()) {
        mapping[another] = i;
      } else {
        return {it->second, i};
      }
    }
    // 不应执行此返回
    return {0, 0};
  }
};
// @lc code=end

#include "leetcode/runner.h"
#include <doctest/doctest.h>

TEST_CASE("0001") {
  auto f = Runner(1, &Solution::twoSum);
  REQUIRE_EQ(f({2, 7, 11, 15}, 9), std::vector{0, 1});
  REQUIRE_EQ(f({3, 2, 4}, 6), std::vector{1, 2});
  REQUIRE_EQ(f({3, 3}, 6), std::vector{0, 1});
}