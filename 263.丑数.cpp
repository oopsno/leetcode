/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
class Solution {
 public:
  bool isUgly(int num) {
    if (num <= 0) {
      return false;
    }
    if (num <= 6) {  // 1, 2, 3, 4(2x2), 5, 6(2x3)
      return true;
    }
    while (num % 2 == 0) {
      num /= 2;
    }
    while (num % 3 == 0) {
      num /= 3;
    }
    while (num % 5 == 0) {
      num /= 5;
    }
    return num == 1;
  }
};
// @lc code=end
