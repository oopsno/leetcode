#include <gtest/gtest.h>
#include "solution/BasicCalculator.cpp"
namespace X224 {

Solution s;
typedef std::pair<std::string, int> case_t;

TEST(BasicCalculator, Utilities) {

}

TEST(BasicCalculator, Functionality) {
  std::vector<case_t> cases = {
      case_t{"1 + 1", 2},
      case_t{" 2-1 + 2 ", 3},
      case_t{"(1+(4+5+2)-3)+(6+8)", 23},
      case_t{"(1-(3-4))", 2}
  };
  for (case_t c : cases) {
    EXPECT_EQ(s.calculate(c.first), c.second);
  }
}

}

