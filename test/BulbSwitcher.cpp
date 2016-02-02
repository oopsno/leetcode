#include <gtest/gtest.h>
#include "solution/BulbSwitcher.cpp"

namespace X319 {

Solution s;

TEST(BulbSwitcher, Functionality) {
  EXPECT_EQ(s.bulbSwitch(10), 3);
}

}
