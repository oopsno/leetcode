#include <gtest/gtest.h>
#include "solution/SumRoottoLeafNumbers.cpp"

namespace X129 {

Solution s;

TEST(SumRoottoLeafNumbers, Empty) {
  EXPECT_EQ(s.sumNumbers(nullptr), 0);
}

TEST(SumRoottoLeafNumbers, Functionality) {
  EXPECT_EQ(s.sumNumbers(TreeNode::build("{1,2,3}")), 25);
  EXPECT_EQ(s.sumNumbers(TreeNode::build("{1,0}")), 10);
}

}
