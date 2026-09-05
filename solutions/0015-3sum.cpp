/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include "leetcode/runner.h"
#include <algorithm>
#include <vector>

class Solution {
private:
  static void dfs(std::vector<std::vector<int>> &results,
                  std::vector<int> trace, const std::vector<int> &candidates,
                  const int index, const int target) noexcept {
    if (trace.size() == 3) {
      if (target == 0) {
        results.emplace_back(std::move(trace));
      }
      return;
    }
    if (index >= candidates.size()) {
      return;
    }
    const int candidate = candidates[index];
    if (candidate > target) {
      return;
    }
    std::vector<int> take_current = trace;
    take_current.emplace_back(candidate);
    dfs(results, std::move(take_current), candidates, index + 1,
        target - candidate);
    dfs(results, std::move(trace), candidates, index + 1, target);
  }

public:
  std::vector<std::vector<int>>
  threeSum(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> results;
    for (int a = 0; a < nums.size();) {
      const int first = nums[a];
      const int target = -first;
      for (int b = a + 1, c = nums.size() - 1; b < nums.size() and b < c;) {
        const int second = nums[b];
        while (b < c and second + nums[c] > target) {
          c -= 1;
        }
        if (b == c) {
          break;
        }
        if (second + nums[c] == target) {
          results.emplace_back(
              std::move(std::vector<int>{first, second, nums[c]}));
        }
        // 跳过相同的 b
        while (b < nums.size() and nums[b] == second) {
          b += 1;
        }
      }
      // 跳过相同的 a
      while (a < nums.size() and nums[a] == first) {
        a += 1;
      }
    }
    return results;
  }
};
// @lc code=end

#include <doctest/doctest.h>

TEST_CASE("0015") {
  using vvi = std::vector<std::vector<int>>;
  auto f = Runner(15, &Solution::threeSum);
  auto nums = std::vector{-1, 0, 1, 2, -1, -4};
  REQUIRE_EQ(f(nums), vvi{{-1, -1, 2}, {-1, 0, 1}});
}
