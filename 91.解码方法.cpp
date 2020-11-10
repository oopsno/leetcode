/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */
#include <string>
#include <vector>

// @lc code=start
class Solution {
 private:
  static bool is_vaild(char lhs, char rhs) noexcept {
    switch (lhs) {
      case '1':
        return '0' <= rhs and rhs <= '9';
      case '2':
        return '0' <= rhs and rhs <= '6';
      default:
        return false;
    }
  }

 public:
  int numDecodings(const std::string code) {
    // 跳过前导 0
    if (code.empty() or code[0] == '0') {
        return 0;
    }
    std::vector<int> m(code.size(), 0);
    /**
     * 状态转移：
     * m[i] 表示 s[0, i] 的解码方法总数，显然 m[0] = 1
     * 1. 若 code[i + 1] != 0, 则 code[i + 1] 一定可以独立解码为一个字符，
     *    即 m[i + 1] = m[i] * 1
     * 2. 若相邻两位 (code[i], code[i + 1]) 必须为 10...26 这 17 种可能之一，
     *    则 (code[i + 1], code[i + 1]) 可以解码为一个字符，
     *    即 m[i + 1] = m[i - 1] * 1
     * 3. 否则视作输入非法，退出并输出 0
     */
    m[0] = 1;
    for (int i = 1; i < code.size(); ++i) {
      bool legal = false;
      if (code[i] != '0') {
        m[i] += m[i - 1];
        legal = true;
      }
      if (is_vaild(code[i - 1], code[i])) {
        if (i > 1) {
          m[i] += m[i - 2];
        } else {
          m[i] += 1;
        }
        legal = true;
      }
      if (not legal) {
        return 0;
      }
    }
    return m.back();
  }
};
// @lc code=end

#include <iostream>

int main() {
  Solution s;
  std::vector xs{"01",
                 "12323232",
                 "12345",
                 "1230",
                 "12306",
                 "00000",
                 "111111111111111111111111111"};
  std::vector ys{0, 12, 3, 0, 0, 0, 317811};
  for (auto i = 0; i < xs.size(); ++i) {
    std::cout << "\"" << xs[i] << "\" -> " << s.numDecodings(xs[i]) << " : "
              << ys[i] << std::endl;
  }
  return 0;
}