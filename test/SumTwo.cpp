#include <gtest/gtest.h>
#include "solution/SumTwo.cpp"

namespace X1 {

Solution s;

std::vector<int> notfound = {0, 0};

TEST(SumTwo, Empty) {
  std::vector<int> empty;
  EXPECT_EQ(s.twoSum(empty, 0), notfound);
}

TEST(SumTwo, OfficialRun) {
  std::vector<int> nums = {3, 2, 4};
  std::vector<int> ans = {2, 3};
  EXPECT_EQ(s.twoSum(nums, 6), ans);
}

}
