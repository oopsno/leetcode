#include <gtest/gtest.h>
#include "solution/ReverseInteger.cpp"
namespace X7 {

Solution s;

TEST(ReverseInteger, Functionality) {
  EXPECT_EQ(s.reverse(1000000003), 0);
  EXPECT_EQ(s.reverse(0), 0);
  EXPECT_EQ(s.reverse(-7), -7);
  EXPECT_EQ(s.reverse(10), 1);
  EXPECT_EQ(s.reverse(-10), -1);
  EXPECT_EQ(s.reverse(INT_MAX), 0);
  EXPECT_EQ(s.reverse(INT_MIN), 0);
}

}

