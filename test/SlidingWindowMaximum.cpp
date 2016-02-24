#include <gtest/gtest.h>
#include "solution/SlidingWindowMaximum.cpp"
namespace X239 {

Solution s;
typedef std::pair<std::vector<int>, std::pair<std::vector<int>, int>> case_t;

TEST(SlidingWindowMaximum, Functionality) {
  const std::vector<case_t> cases{
      {{3, 3, 5, 5, 6, 7}, {{1, 3, -1, -3, 5, 3, 6, 7}, 3}},
      {{3}, {{1, 3, -1}, 3}}
  };
  for (const case_t &c : cases) {
    EXPECT_EQ(c.first, s.maxSlidingWindow(c.second.first, c.second.second));
  }
}

}

