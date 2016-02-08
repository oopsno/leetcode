#include <gtest/gtest.h>
#include "solution/EvalRPN.cpp"
namespace X150 {

typedef std::pair<std::vector<std::string>, int> case_t;

Solution s;

TEST(EvalRPN, Functionality) {
  std::vector<case_t> cases = {
      case_t{{"2", "1", "+", "3", "*"}, 9},
      case_t{{"4", "13", "5", "/", "+"}, 6},
      case_t{{"3","-4","+"}, -1}
  };
  for (case_t c : cases) {
    EXPECT_EQ(s.evalRPN(c.first), c.second);
  }
}

}

