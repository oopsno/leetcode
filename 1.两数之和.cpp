/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(const std::vector<int> &nums, const int target) const noexcept {
    std::unordered_map<int, int> mapping;
    for (int i = 0; i < nums.size(); ++i) {
      const int num = nums[i];
      const int another = target - num;
      const auto it = mapping.find(num);
      if (it == mapping.cend()) {
        mapping[another] = i;
      } else {
        return {it->second, i};
      }
    }
    // 不应执行此返回
    return {0, 0};
  }
};
// @lc code=end