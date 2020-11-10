/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
#include <string>
class Solution {
public:
  std::string convert(const std::string s, const int numRows) const noexcept {
    // 处理无需折叠的情况
    if (numRows <= 1 or s.size() < numRows) {
      return s;
    }
    // 预先分配结果
    std::string result(s.size(), ' ');
    std::size_t cursor = 0;
    const int t = 2 * numRows - 2; // t >= 2
    for (int i = 0; i < s.size(); ++i) {
      const int r = i % t;
      for (int base = 0; base < numRows; ++base) {
        if (r == base or r == t - base) {
          result[i] = s[i];
          break;
        }
      }
    }
    return result;
  }
};

#include <iostream>
int main() {
  Solution s;
  std::cout << s.convert("LEETCODEISHIRING", 3) << std::endl;
  std::cout << "LCIRETOESIIGEDHN" << std::endl;
  std::cout << s.convert("LEETCODEISHIRING", 4) << std::endl;
  std::cout << "LDREOEIIECIHNTSG" << std::endl;
}
// @lc code=end
