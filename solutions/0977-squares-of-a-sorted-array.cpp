/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */
#include <algorithm>
#include <iterator>
#include <vector>
// @lc code=start
class Solution {
 private:
  static constexpr inline int square(const int x) noexcept { return x * x; };

 public:
  std::vector<int> sortedSquares(const std::vector<int>& A) const noexcept {
    std::vector<int> result;
    result.reserve(A.size());
    auto it = std::back_inserter(result);
    if (A.front() >= 0) {
      std::transform(A.cbegin(), A.cend(), it, square);
    } else if (A.back() <= 0) {
      std::transform(A.crbegin(), A.crend(), it, square);
    } else {
      int neg = 0, pos = 0;
      while (A[pos] < 0) {
        pos += 1;
      }
      neg = pos - 1;
      while (neg >= 0 and pos < A.size()) {
        const auto lhs = std::abs(A[neg]);
        const auto rhs = std::abs(A[pos]);
        if (lhs < rhs) {
          *it++ = square(lhs);
          neg -= 1;
        } else {
          *it++ = square(rhs);
          pos += 1;
        }
      }
      while (neg >= 0) {
        *it++ = square(A[neg--]);
      }
      while (pos < A.size()) {
        *it++ = square(A[pos++]);
      }
    }
    return result;
  }
};
// @lc code=end
