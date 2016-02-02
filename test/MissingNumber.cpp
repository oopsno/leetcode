#include <gtest/gtest.h>
#include "solution/MissingNumber.cpp"

namespace X268 {

Solution s;

TEST(MissingNumber, SumUpTo) {
  EXPECT_EQ(Solution::sum_up_to(100), 5050);
}

TEST(MissingNumber, Functionality) {
  typedef std::pair<int, std::vector<int>> case_t;
  std::vector<case_t> cases = {case_t(2, {0, 1, 3}),
                               case_t(0, {1})};
  for (auto c : cases) {
    EXPECT_EQ(s.missingNumber(c.second), c.first);
  }
}

}

