#include <gtest/gtest.h>
#include "solution/SumTwo.cpp"

namespace X1 {

Solution s;

std::vector<int> notfound = {0, 0};

TEST(SumTwo, Empty) {
  std::vector<int> empty;
  EXPECT_EQ(s.twoSum(empty, 0), notfound);
}

TEST(SumTwo, Run) {
  int target = 6;
  std::vector<int> nums = {3, 2, 4};
  std::vector<int> ans = {2, 3};
  EXPECT_EQ(s.twoSum(nums, target), ans);
}

TEST(SumTwo, Zeros) {
  int target = 0;
  std::vector<int> nums = {0, 4, 2, 0};
  std::vector<int> ans = {1, 4};
  EXPECT_EQ(s.twoSum(nums, target), ans);
}

TEST(SumTwo, Negtive) {
  int target = 0;
  std::vector<int> nums = {-9, 4, 2, 9};
  std::vector<int> ans = {1, 4};
  EXPECT_EQ(s.twoSum(nums, target), ans);
}

}
