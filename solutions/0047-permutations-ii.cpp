/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II / Permutations II
 *
 * Given a collection of numbers, `nums`, that might contain duplicates,
 * return all possible unique permutations in any order.
 */

// @lc code=start
#include <algorithm>
#include <utility> // for std::as_const
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
  std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums) {
    if (nums.empty()) {
      return {};
    }
    if (nums.size() == 1) {
      return {nums};
    }
    // 字典序法
    std::vector<std::vector<int>> results;
    // 先排序, 等到达最大排列的时候停止生成
    std::sort(nums.begin(), nums.end());
    while (true) {
      // 添加当前排列
      results.push_back(nums);
      // 1. 从右向左搜索第一个下降点 nums[i] < nums[i + 1]
      int i = nums.size() - 2;
      while (i >= 0 && nums[i] >= nums[i + 1]) {
        i -= 1;
      }
      if (i < 0) {
        // 没有下降点 => 现在是最大排列, 生成结束
        return results;
      }
      // 2. 从右向左搜索第一个 nums[j] > nums[i]
      // 现在不是最大排列，所以一定存在 i != j 满足条件
      int j = nums.size() - 1;
      while (nums[i] >= nums[j]) {
        j -= 1;
      }
      // 3. 交换 i/j, 然后反转 nums[i + 1:]
      std::swap(nums[i], nums[j]);
      std::reverse(nums.begin() + i + 1, nums.end());
    }
  }
};
// @lc code=end

#include "leetcode/runner.h"
#include <doctest/doctest.h>

static std::vector<std::vector<int>> ground_truth(const std::vector<int> &xs) {
  std::vector dup{xs};
  std::sort(dup.begin(), dup.end());
  std::vector<std::vector<int>> results{dup};
  while (std::next_permutation(dup.begin(), dup.end())) {
    results.push_back(dup);
  }
  return results;
}

TEST_CASE("0047") {
  auto f = Runner(47, &Solution::permuteUnique);
  using vvi = std::vector<std::vector<int>>;
  SUBCASE("example 1") {
    auto xs = std::vector{1, 1, 2};
    auto expected = ground_truth(xs);
    REQUIRE_EQ(f(xs), expected);
  }
  SUBCASE("example 2") {
    auto xs = std::vector{1, 2, 3};
    auto expected = ground_truth(xs);
    REQUIRE_EQ(f(xs), expected);
  }
}