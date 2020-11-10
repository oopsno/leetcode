/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include <algorithm>
#include <vector>
class Solution {
  static void dfs(std::vector<std::vector<int>> &results,
                  const std::vector<int> &xs, const int index,
                  std::vector<int> current, const int target) {
    if (target == 0) {
      std::sort(current.begin(), current.end());
      if (std::find(results.cbegin(), results.cend(), std::as_const(current)) == results.cend()) {
        results.emplace_back(std::move(current));
      }
      return;
    }
    if (target < 0 or index >= xs.size()) {
      return;
    }
    const int candidate = xs[index];
    if (candidate > target) {
      return;
    }
    std::vector<int> take = current;
    take.emplace_back(candidate);
    dfs(results, xs, index + 1, std::move(take), target - candidate);
    dfs(results, xs, index + 1, std::move(current), target);
  }

public:
  std::vector<std::vector<int>>
  combinationSum2(const std::vector<int> &candidates, int target) {
    std::vector<std::vector<int>> results;
    std::vector<int> xs;
    for (int candidate : candidates) {
      xs.emplace_back(candidate);
    }
    std::sort(xs.begin(), xs.end());
    dfs(results, std::as_const(xs), 0, {}, target);
    return results;
  }
};
// @lc code=end
