/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 第k个排列
 */

// @lc code=start
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

static const int F[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

class Solution {
public:
  std::string getPermutation(int n, int k) const noexcept {
    // 构造第一个排列
    std::vector<int> digits(n, 0);
    for (auto i = 0; i < n; ++i) {
      digits[i] = i + 1;
    }
    // 令 n 从 0 开始计数
    k -= 1;
    // 计算第 k 个排列
    for (auto base = 0; base < n and k > 0; ++base) {
      // 确定第 base 高位
      const auto d = std::div(k, F[n - base - 1]);
      if (d.quot > 0) {
        std::swap(digits[base], digits[base + d.quot]);
        // 重排序剩余字符
        std::sort(digits.begin() + base + 1, digits.end());
      }
      // 节余
      k = d.rem;
    }
    // 转为字符串
    std::string result(n, ' ');
    for (auto i = 0; i < n; ++i) {
      result[i] = '0' + digits[i];
    }
    return result;
  }
};
// @lc code=end