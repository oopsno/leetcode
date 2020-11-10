/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
private:
  static void dfs(std::vector<std::vector<int>> &results,
                  std::vector<int> combination,
                  const std::vector<int> &candidates, const int index,
                  const int target) noexcept {
    if (target == 0) {
      results.emplace_back(std::move(combination));
      return;
    }
    if (target <= 0 or index >= candidates.size()) {
      return;
    }
    const int candidate = candidates[index];
    if (candidate > target) {
      return;
    }
    std::vector<int> take_current = combination;
    take_current.emplace_back(candidate);
    dfs(results, std::move(combination), candidates, index + 1, target);
    dfs(results, std::move(take_current), candidates, index, target - candidate);
  }

  static void bfs(std::vector<std::vector<int>> &results,
                  std::vector<int> combination,
                  const std::vector<int> &candidates, const int index,
                  const int target) noexcept {
    if (target == 0) {
      results.emplace_back(std::move(combination));
    }
    if (target <= 0 or index >= candidates.size()) {
      return;
    }
    const int candidate = candidates[index];
    if (candidate > target) {
      return;
    }
    for (int t = 0; t < target / candidate; ++t) {
        bfs(results, combination, candidates, index + 1, target - t * candidate);
        combination.emplace_back(candidate);
    }
  }

public:
  std::vector<std::vector<int>>
  combinationSum(const std::vector<int> &candidates, const int target) {
    // 分配结果
    std::vector<std::vector<int>> results;
    // 剔除不小于 target 的候选元素并按升序排序
    std::vector<int> reasonable_candidates;
    for (int candidate : candidates) {
      if (candidate < target) {
        reasonable_candidates.emplace_back(candidate);
      }
      if (candidate == target) {
        results.emplace_back(1, target);
      }
    }
    std::sort(reasonable_candidates.begin(), reasonable_candidates.end());
    // 搜索所有可行解
    dfs(results, {}, std::as_const(reasonable_candidates), 0, target);
    return results;
  }
};
// @lc code=end
