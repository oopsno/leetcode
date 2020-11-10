/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
#include <vector>
#include <algorithm>
class Solution {
    std::vector<std::vector<int>> make_cache(size_t num_levels) {
        std::vector<std::vector<int>> cache(num_levels);
        for (auto i = 0; i < num_levels; ++i) {
            cache[i].resize(i + 1);
        }
        return cache;
    }
public:
  int minimumTotal(std::vector<std::vector<int>> &triangle) {
      auto cache = make_cache(triangle.size());
      cache[0][0] = triangle[0][0];
      for (auto level = 1; level < triangle.size(); ++level) {
        cache[level][0] = triangle[level][0] + cache[level - 1][0];
        cache[level][level] = triangle[level][level] + cache[level - 1][level - 1];
        for (auto i = 1; i < level; ++i) {
          cache[level][i] =
              triangle[level][i] +
              std::min(cache[level - 1][i - 1], cache[level - 1][i]);
        }
      }
      return *std::min_element(cache.back().cbegin(), cache.back().cend());
  }
};
// @lc code=end

#include <iostream>
int main() {
  Solution s;
  std::vector<std::vector<int>> tree{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  std::cout << s.minimumTotal(tree) << std::endl;
  return 0;
}