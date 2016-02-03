#include <gtest/gtest.h>
#include "solution/ZigZag.cpp"
namespace X6 {

Solution s;
typedef int case_t;

TEST(ZigZag, Utilities) {
  Solution::trace_t trace_4 = 4;
  EXPECT_EQ(trace_4.next(), 0);
  EXPECT_EQ(trace_4.next(), 1);
  EXPECT_EQ(trace_4.next(), 2);
  EXPECT_EQ(trace_4.next(), 3);
  EXPECT_EQ(trace_4.next(), 2);
  EXPECT_EQ(trace_4.next(), 1);
  EXPECT_EQ(trace_4.next(), 0);
  EXPECT_EQ(trace_4.next(), 1);
  Solution::trace_t trace_1 = Solution::trace_t(1);
  EXPECT_EQ(trace_1.next(), 0);
  EXPECT_EQ(trace_1.next(), 0);
  EXPECT_EQ(trace_1.next(), 0);
  Solution::trace_t trace_2 = Solution::trace_t(2);
  EXPECT_EQ(trace_2.next(), 0);
  EXPECT_EQ(trace_2.next(), 1);
  EXPECT_EQ(trace_2.next(), 0);
  EXPECT_EQ(trace_2.next(), 1);
  EXPECT_EQ(trace_2.next(), 0);
}

TEST(ZigZag, Functionality) {
  EXPECT_EQ(s.convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
  EXPECT_EQ(s.convert("ABCD", 3), "ABDC");
}

}

