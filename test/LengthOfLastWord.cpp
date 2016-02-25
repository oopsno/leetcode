#include <gtest/gtest.h>
#include "solution/LengthOfLastWord.cpp"
namespace X58 {

Solution s;
typedef std::pair<int, std::string> case_t;

TEST(LengthOfLastWord, Functionality) {
  const std::vector<case_t> cases{
      {5, "Hello World"},
      {5, "space"},
      {1, "a "},
      {0, ""},
  };
  for (const case_t &c : cases) {
    EXPECT_EQ(c.first, s.lengthOfLastWord(c.second));
  }
}

}

