/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
private:
  static int count_ones(int n) noexcept {
    int ones = 0;
    while (n != 0) {
      ones += 1;
      n &= n - 1;
    }
    return ones;
  }

public:
  int hammingDistance(int x, int y) { return count_ones(x ^ y); }
};
// @lc code=end
