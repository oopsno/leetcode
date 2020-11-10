/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
// @lc code=start
#include <string>
#include <tuple>
#include <vector>

// clang-format off
const char *ALPHABET[8] = {
            "abc",  "def",
    "ghi",  "jkl",  "mno",
    "pqrs", "tuv", "wxyz"
};

constexpr size_t ALPHABET_SIZE[8] = {
       3, 3,
    3, 3, 3,
    4, 3, 4
};
// clang-format on

std::tuple<size_t, std::vector<size_t>>
result_length(const std::string &digits) noexcept {
  size_t result = 1;
  std::vector<size_t> periods(digits.size(), 0);
  for (int i = digits.size() - 1; i >= 0; --i) {
    const char digit = digits[i];
    periods[i] = result;
    result *= ALPHABET_SIZE[digit - '2'];
  }
  return std::make_tuple(result, periods);
}

class Solution {
public:
  std::vector<std::string>
  letterCombinations(const std::string digits) const noexcept {
    // 处理空值
    if (digits.empty()) {
      return {};
    }
    // 计算结果数量和各位更新周期
    const auto [num_results, periods] = result_length(digits);
    // 为结果预分配内存
    std::vector<std::string> results(num_results,
                                     std::string(digits.size(), ' '));
    // 构造结果
    for (auto i = 0; i < digits.size(); ++i) {
      const char digit = digits[i];
      size_t alphabet_size = ALPHABET_SIZE[digit - '2'];
      const char *alphabet = ALPHABET[digit - '2'];
      for (auto step = 0; step < num_results; ++step) {
        results[step][i] = alphabet[step / periods[i] % alphabet_size];
      }
    }
    return results;
  }
};
// @lc code=end