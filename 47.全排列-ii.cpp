/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
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
  std::vector<std::vector<int>> permuteUnique(
      std::vector<int> &nums) const noexcept {
    if (nums.empty()) {
        return {};
    }
    if (nums.size() == 1) {
        return {nums};
    }
    std::vector<std::vector<int>> results;
    std::sort(nums.begin(), nums.end());
    while (true) {
      // 添加当前排列
      results.emplace_back(std::as_const(nums));
      // 生成下一排列
      bool have_next = true;
      for (int j = nums.size() - 2; j >= 0; --j) {
        if (nums[j] < nums[j + 1]) {
          for (int l = nums.size() - 1; l > j; --l) {
            if (nums[j] < nums[l]) {
              std::swap(nums[j], nums[l]);
              std::reverse(nums.begin() + j + 1, nums.end());
              break;
            }
          }
          break;
        }
        if (j == 0) {
            have_next = false;
        }
      }
      if (not have_next) {
          break;
      }
    }
    return results;
  }
};
// @lc code=end

#include <fmt/core.h>
#include <fmt/ranges.h>

#include <iostream>
int main() {
  Solution s;
  std::vector<int> numbers{1, 2, 1, 2};
  for (auto p : s.permuteUnique(numbers)) {
    std::cout << fmt::format("{}", p) << std::endl;
  }
  return 0;
}