#include <gtest/gtest.h>
#include "solution/PeekingIterator.cpp"
namespace X284 {

const std::vector<int> fibs{1, 1, 2, 3, 5, 8, 13, 21};
const std::vector<int> three{1, 2, 3};

TEST(PeekingIterator, hasNext) {
  PeekingIterator step(fibs);
  std::vector<bool> steps(fibs.size());
  std::generate(steps.begin(), steps.end(), [&]() {
    bool state = step.hasNext();
    step.next();
    return state;
  });
  EXPECT_TRUE(std::all_of(steps.cbegin(), steps.cend(), [](bool sig) {
    return sig;
  }));
  EXPECT_FALSE(step.hasNext());
}

TEST(PeekingIterator, next) {
  PeekingIterator duplicate(fibs);
  std::vector<int> duplication(fibs.size());
  std::generate(duplication.begin(), duplication.end(), [&]() {
    return duplicate.next();
  });
  EXPECT_EQ(duplication, fibs);
  EXPECT_FALSE(duplicate.hasNext());
}

TEST(PeekingIterator, peek) {
  PeekingIterator it = three;
  EXPECT_EQ(it.peek(), 1);
  EXPECT_EQ(it.next(), 1);
  EXPECT_EQ(it.next(), 2);
  EXPECT_EQ(it.peek(), 3);
  EXPECT_TRUE(it.hasNext());
  EXPECT_EQ(it.next(), 3);
  EXPECT_FALSE(it.hasNext());
  EXPECT_THROW(it.peek(), std::out_of_range);
}

}

