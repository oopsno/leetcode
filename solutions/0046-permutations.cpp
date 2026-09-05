/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列 / Permutations
 *
 * Given an array `nums` of distinct integers,
 * return all the possible permutations.
 * You can return the answer in any order.
 */

// @lc code=start
#include <algorithm>
#include <vector>
class Solution {
private:
  static inline int fact(int n) {
    int f = 1;
    while (n > 1) {
      f *= n--;
    }
    return f;
  }

public:
  std::vector<std::vector<int>> permute(std::vector<int> &nums) {
    if (nums.empty()) {
      return {};
    }
    if (nums.size() == 1) {
      return {nums};
    }
    const int total = fact(nums.size());
    std::vector<std::vector<int>> results;
    for (int counter = 0; counter < total; ++counter) {
      // 添加当前排列
      results.push_back(nums);
      // 生成下一排列
      int i = nums.size() - 2;
      // 1. 从右向左找第一个下降点
      while (i >= 0 && !(nums[i] < nums[i + 1])) {
        i -= 1;
      }
      if (i < 0) {
        // 当前是最小排列
        std::reverse(nums.begin(), nums.end());
        continue;
      }
      // 从右向左搜索第一个比 nums[i] 大的元素
      int j = nums.size() - 1;
      while (nums[j] <= nums[i]) {
        j -= 1;
      }
      // 3. 交换
      std::swap(nums[i], nums[j]);
      std::reverse(nums.begin() + (i + 1), nums.end());
    }
    return results;
  }
};
// @lc code=end

#include "leetcode/runner.h"
#include <doctest/doctest.h>

TEST_CASE("0046") {
  auto f = Runner(46, &Solution::permute);
  using vvi = std::vector<std::vector<int>>;
  SUBCASE("example 1") {
    auto xs = std::vector{1, 2, 3};
    REQUIRE_EQ(
        f(xs),
        vvi{{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}});
  }
  SUBCASE("example 2") {
    auto xs = std::vector{0, 1};
    REQUIRE_EQ(f(xs), vvi{{0, 1}, {1, 0}});
  }
  SUBCASE("example 3") {
    auto xs = std::vector{1};
    REQUIRE_EQ(f(xs), vvi{{1}});
  }
}