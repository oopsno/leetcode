/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
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
  threeSum(std::vector<int> &nums) const noexcept {
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

#include <iostream>

int main() {
  Solution s;
  std::vector<int> nums{
      -7,  -10, -1,  3,  0,   -7,  -9, -1, 10, 8,   -6,  4,   14,  -8, 9,   -15,
      0,   -4,  -5,  9,  11,  3,   -5, -8, 2,  -6,  -14, 7,   -14, 10, 5,   -6,
      7,   11,  4,   -7, 11,  11,  7,  7,  -4, -14, -12, -13, -14, 4,  -13, 1,
      -15, -2,  -12, 11, -14, -2,  10, 3,  -1, 11,  -5,  1,   -2,  7,  2,   -10,
      -5,  -8,  -10, 14, 10,  13,  -2, -9, 6,  -7,  -7,  7,   12,  -5, -14, 4,
      0,   -11, -8,  2,  -6,  -13, 12, 0,  5,  -15, 8,   -12, -1,  -4, -15, 2,
      -5,  -9,  -7,  12, 11,  6,   10, -6, 14, -12, 9,   3,   -10, 10, -8,  -2,
      6,   -9,  7,   7,  -7,  4,   -8, 5,  -4, 8,   0,   3,   11,  0,  -10, -9};
  const auto results = s.threeSum(nums);
  std::cout << "length = " << results.size() << std::endl;
  for (const auto &triplet : results) {
    std::cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2]
              << "]" << std::endl;
  }
  return 0;
}
