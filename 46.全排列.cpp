/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
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
  std::vector<std::vector<int>> permute(
      const std::vector<int> &nums) const noexcept {
    if (nums.empty()) {
        return {};
    }
    if (nums.size() == 1) {
        return {nums};
    }
    const int total = fact(nums.size());
    std::vector<std::vector<int>> results(total, std::vector<int>(nums.size()));
    // 初始化索引
    std::vector<int> index(nums.size());
    for (int i = 0; i < index.size(); ++i) {
      index[i] = i;
    }
    for (int i = 0; i < total; ++i) {
      // 添加当前排列
      for (int j = 0; j < nums.size(); ++j) {
        results[i][j] = nums[index[j]];
      }
      // 生成下一排列
      for (int j = index.size() - 2; j >= 0; --j) {
        if (index[j] < index[j + 1]) {
          for (int l = index.size() - 1; l > j; --l) {
            if (index[j] < index[l]) {
              std::swap(index[j], index[l]);
              std::reverse(index.begin() + j + 1, index.end());
              break;
            }
          }
          break;
        }
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
  const std::vector<int> numbers{1, 2, 3, 4};
  for (auto p : s.permute(numbers)) {
    std::cout << fmt::format("{}", p) << std::endl;
  }
  return 0;
}