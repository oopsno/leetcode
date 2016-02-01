#include <gtest/gtest.h>
#include "solution/SingleNumber.cpp"

namespace X136 {

Solution s;

TEST(SingleNumber, I) {
  std::vector<int> seq = {1, 2, 3, 4, 3, 2, 1};
  std::vector<int> single = {1};
  EXPECT_EQ(s.singleNumber(seq), 4);
  EXPECT_EQ(s.singleNumber(single), 1);
}

}


namespace X137 {

Solution s;

TEST(SingleNumber, II) {
  std::vector<int> seq = {1, 1, 1, 2, 2, 4, 2, 3, 3, 3};
  std::vector<int> single = {1};
  EXPECT_EQ(s.singleNumber(seq), 4);
  EXPECT_EQ(s.singleNumber(single), 1);
}

}


namespace X260 {

Solution s;

TEST(SingleNumber, III) {
  std::vector<int> seq = {1, 1, 2, 4, 2, 3};
  std::vector<int> answer = {3, 4};
  std::vector<int> result = s.singleNumber(seq);
  std::sort(result.begin(), result.end());
  EXPECT_EQ(result, answer);
}

}
