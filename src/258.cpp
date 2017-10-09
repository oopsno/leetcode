/**
 * 258. Add Digits
 */

class Solution {
 public:
  int addDigits(int num) {
    const auto rem = num % 9;
    if (num == 0) {
      return 0;
    }
    return rem > 0 ? rem : 9;
  }
};

#include <cstdlib>
#include <gtest/gtest.h>

static int addDigits(int x) {
  int y = 0;
  for (auto m = std::div(x, 10); x != 0; x = m.quot, m = std::div(x, 10)) {
    y += m.rem;
  }
  return y < 10 ? y : addDigits(y);
}

TEST(AddDigits, Testcases) {
  Solution solution;
  for (auto x = 0; x < 10000; ++x) {
    ASSERT_EQ(solution.addDigits(x), addDigits(x));
  }
}
