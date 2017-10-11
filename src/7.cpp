/**
 * 7. Reverse Integer
 */

#include <cstdlib>
#include <cmath>
#include <cstdint>

class Solution {
 public:
  int reverse(int x) {
    const auto sig = std::signbit(x);
    x = std::abs(x);
    int64_t y = 0;
    while (x > 0) {
      const auto m = std::div(x, 10);
      y = y * 10 + m.rem;
      x = m.quot;
      if (y > std::numeric_limits<int>::max()) {
        return 0;
      }
    }
    const auto r = static_cast<int>(y);
    return sig ? -r : r;
  }
};

#include <gtest/gtest.h>

TEST(ReverseInteger, Testcases) {
  Solution solution;
  ASSERT_EQ(solution.reverse(123), 321);
  ASSERT_EQ(solution.reverse(-123), -321);
  ASSERT_EQ(solution.reverse(1534236469), 0);
  ASSERT_EQ(solution.reverse(std::numeric_limits<int>::max()), 0);
  ASSERT_EQ(solution.reverse(std::numeric_limits<int>::min()), 0);
}
