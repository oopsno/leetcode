#include <gtest/gtest.h>
#include "solution/UniqueBinarySearchTrees.cpp"
namespace X96 {

Solution s;
typedef std::pair<int, int> case_t;

TEST(UniqueBinarySearchTrees, Functionality) {
  std::vector<case_t> cases = {
      case_t(0, 0),
      case_t(1, 1),
      case_t(2, 2),
      case_t(3, 5),
      case_t(4, 14),
      case_t(5, 42),
      case_t(6, 132),
  };
  for (case_t c : cases) {
    EXPECT_EQ(s.numTrees(c.first), c.second);
  }
}

}

