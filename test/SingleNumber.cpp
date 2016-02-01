#include <gtest/gtest.h>
#include "solution/SingleNumber.cpp"

namespace X136 {

Solution s;

TEST(SingleNumber, Functionality) {
  std::vector<int> seq = {1, 2, 3, 4, 3, 2, 1};
  std::vector<int> single = {1};
  EXPECT_EQ(s.singleNumber(seq), 4);
  EXPECT_EQ(s.singleNumber(single), 1);
}

}