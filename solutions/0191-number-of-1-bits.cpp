/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
#include <cstdint>

class Solution {
public:
  int hammingWeight(uint32_t n) const noexcept {
    int ones = 0;
    while (n != 0) {
      ones += 1;
      n &= n - 1;
    }
    return ones;
  }
};
// @lc code=end
