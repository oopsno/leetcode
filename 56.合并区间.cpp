/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

#include <algorithm>
#include <vector>

// @lc code=start
class Solution {
 private:
  static bool merge_inplace(std::vector<int>& lhs,
                            const std::vector<int>& rhs) noexcept {
    const int a = lhs.front(), b = lhs.back();  // a <= b
    const int c = rhs.front(), d = rhs.back();  // c <= d
    // 若两端完全相离
    if (b < c or d < a) {
      return false;
    } else {
      lhs.front() = std::min(a, c);
      lhs.back() = std::max(b, d);
      return true;
    }
  }

  static bool compare(const std::vector<int>& lhs,
                      const std::vector<int>& rhs) noexcept {
    return lhs.front() < rhs.front();
  }

 public:
  std::vector<std::vector<int>> merge(
      std::vector<std::vector<int>>& intervals) {
    if (intervals.size() < 2) {
      return intervals;
    }
    std::sort(intervals.begin(), intervals.end(), compare);
    std::vector<std::vector<int>> result;
    result.emplace_back(intervals.front());
    for (size_t i = 1; i < intervals.size(); ++i) {
      auto& left = result.back();
      const auto& right = intervals[i];
      if (not merge_inplace(left, right)) {
        result.emplace_back(right);
      }
    }
    return result;
  }
};
// @lc code=end
