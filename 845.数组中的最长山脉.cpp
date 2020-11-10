/*
 * @lc app=leetcode.cn id=845 lang=cpp
 *
 * [845] 数组中的最长山脉
 */

#include <algorithm>
#include <tuple>
#include <vector>

#include "leetcode.hpp"

// @lc code=start
class Solution {
 private:
  /**
   * 计算连续子数组 {xs[begin], ...,  xs[end]} 是否构成山脉
   */
  static inline int next_mountain(const std::vector<int>& xs, int& begin,
                                  int& peak, int& end) noexcept {
    while (end < xs.size() and xs[begin] >= xs[peak]) {
      begin += 1;
      peak += 1;
      end += 1;
    }
    if (end == xs.size()) {
      return 0;
    }
    // 此时 xs[begin] < xs[peak]
    while (end < xs.size() and xs[peak] < xs[peak + 1]) {
      peak += 1;
      end += 1;
    }
    if (end == xs.size() or xs[peak] == xs[peak + 1]) {
      return 0;
    }
    // 此时 xs[peak] > xs[end]
    while (end < xs.size() and xs[end - 1] > xs[end]) {
      end += 1;
    }
    // 此时 end 位于右侧山脚后一元素
    end -= 1;
    return end - begin + 1;
  }

  static inline void skip(int& begin, int& peak, int& end) noexcept {
    begin = end;
    peak = begin + 1;
    end = peak + 1;
  }

 public:
  int longestMountain(const std::vector<int>& A) const noexcept {
    // 山脉长度至少为 3
    if (A.size() < 3) {
      return 0;
    }
    // 定位第一座山脉
    int begin = 0, peak = 1, end = 2, length = 0;
    while (end < A.size()) {
      length = std::max(length, next_mountain(A, begin, peak, end));
      skip(begin, peak, end);
    }
    return length;
  }
};
// @lc code=end

SolutionWrapper sw{845,
                   "数组中的最长山脉",
                   &Solution::longestMountain,
                   {{{{2, 1, 4, 7, 3, 2, 5}}, 5}, {{{2, 2, 2}}, 0}}};

#if (defined(WITH_MAIN))
int main(int argc, char* argv[]) { return Program(argc, argv, sw).run(); }
#endif