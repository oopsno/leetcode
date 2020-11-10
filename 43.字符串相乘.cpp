/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// @lc code=start
class Solution {
private:
  static std::vector<int>
  prepare_big_number(const std::string &literal) noexcept {
    constexpr int zero = '0';
    std::vector<int> number(literal.size(), 0);
    auto it = literal.crbegin();
    std::generate(number.begin(), number.end(), [&]() { return *it++ - zero; });
    return number;
  }
  static inline int add_with_carry(int x, int &carry) noexcept {
    const auto d = std::div(x + carry, 10);
    carry = d.quot;
    return d.rem;
  }
  static void mul(const std::vector<int> &number, int base,
                  std::vector<int> &output) noexcept {
    int carry = 0;
    for (int i = 0; i < number.size(); ++i) {
      output[i] = add_with_carry(number[i] * base, carry);
    }
    output.back() = carry;
  }
  static void add(std::vector<int> &sum, const std::vector<int> operand,
                  int offset) noexcept {
    int carry = 0, i = 0;
    for (; i < operand.size(); ++i) {
      sum[i + offset] = add_with_carry(sum[i + offset] + operand[i], carry);
    }
    for (; i + offset < sum.size() and carry != 0; ++i) {
      sum[i + offset] = add_with_carry(sum[i + offset], carry);
    }
  }

public:
  std::string multiply(std::string lhs, std::string rhs) const noexcept {
    // 快速跳过乘数中含有 0 和 1 的情况
    if (lhs == "0" or rhs == "0") {
      return "0";
    }
    if (lhs == "1") {
      return rhs;
    }
    if (rhs == "1") {
      return lhs;
    }
    // 创建最终结果
    const size_t maximum_output_digits = lhs.size() + rhs.size();
    std::vector<int> production(maximum_output_digits, 0);
    // 预先创建中间结果, 至多 lhs.size() + 1 位
    std::vector<int> intermediate(lhs.size() + 1, 0);
    // 乘法
    const std::vector<int> lhs_ = prepare_big_number(lhs);
    const std::vector<int> rhs_ = prepare_big_number(rhs);
    for (int i = 0; i < rhs_.size(); ++i) {
      const int base = rhs_[i];
      mul(lhs_, base, intermediate);
      add(production, intermediate, i);
    }
    // 移除先导 0
    if (production.back() == 0) {
        production.pop_back();
    }
    // 格式化输出
    std::string literal_result(production.size(), '-');
    for (auto i = 0; i < production.size(); ++i) {
      literal_result[i] = production[production.size() - 1 - i] + '0';
      if (production[production.size() - 1 - i] > 9) {
      }
    }
    return literal_result;
  }
};
// @lc code=end

int main() {
  Solution s;
  std::string m = s.multiply("123", "456");
  std::cout << m.size() << ": " << m << std::endl;
}