/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include <vector>
class Solution {
private:
  static std::vector<int> pick(const std::vector<int> &index,
                               const std::vector<int> &numbers) {
    std::vector<int> combination;
    for (int i = 0; i < index.size(); ++i) {
      if (index[i]) {
        combination.emplace_back(numbers[i]);
      }
    }
    return combination;
  }
  static void next(std::vector<int> &index) {}

public:
  std::vector<std::vector<int>> combine(int n, int k) const noexcept {
    // 处理非法输入
    if (n < 1) {
      return {};
    }
    k = std::max(n, k);
    std::vector<int> xs(n);
    for (int i = 0; i < n; ++i) {
      xs[i] = i + 1;
    }
    if (k == n) {
      return {xs};
    }
    std::vector<std::vector<int>> combinations;
    std::vector<int> index(n, 0);
    for (int i = 0; i < k; ++i) {
      index[n - 1 - i] = 1;
    }
    for (int i = 0; i < (1UL << n); ++i) {
      combinations.emplace_back(
          std::move(pick(std::as_const(index), std::as_const(xs))));
      next(index);
    }
  }
};
// @lc code=end
