/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */
#include <algorithm>
#include <limits>
#include <vector>

// @lc code=start
class Solution {
 public:
  int lengthOfLIS(const std::vector<int>& nums) const noexcept {
    if (nums.size() < 2) {
      return nums.size();
    }
    std::vector<int> m(nums.size(), 1);
    int result = 1;
    for (int end = 1; end < nums.size(); ++end) {
      for (int begin = 0; begin < end; begin++) {
        if (nums[begin] < nums[end]) {
          m[end] = std::max(m[begin] + 1, m[end]);
        }
      }
      result = std::max(result, m[end]);
    }
    return result;
  }

  int fastLengthOfLIS(const std::vector<int>& nums) const noexcept {
    constexpr int min = std::numeric_limits<int>::min();
    constexpr int max = std::numeric_limits<int>::max();
    if (nums.size() < 2) {
      return nums.size();
    }
    std::vector<int> d(nums.size() + 1, max);
    d[0] = min;
    for (const int num : nums) {
      const auto it = std::upper_bound(d.begin(), d.end(), num);
      const auto prev = it - 1;
      if (*prev < num and num < *it) {
        *it = num;
      }
    }
    const auto p = [](int x) { return x < max; };
    const auto it = std::find_if(d.crbegin(), d.crend(), p);
    return nums.size() - std::distance(d.crbegin(), it);
  }
};
// @lc code=end
