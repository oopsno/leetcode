/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

// @lc code=start
class Solution {
public:
  int rangeBitwiseAnd(int m, int n) const noexcept {
    if (((~m) & n) > m) {
        return 0;
    } else {
        return m & n;
    }
  }
};
// @lc code=end

#include <iostream>

int main() {
  auto s = Solution();
  std::cout << s.rangeBitwiseAnd(0, 1) << std::endl;
  return 0;
}
