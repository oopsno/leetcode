#include <gtest/gtest.h>
#include "solution/LinkedListCycle.cpp"
namespace X141 {

Solution s;

TEST(LinkedListCycle, Functionality) {
  const std::vector<int> e = {1, 2};
  EXPECT_FALSE(s.hasCycle(ListNode::build(e)));
}

}

