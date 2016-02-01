#include <gtest/gtest.h>
#include <algorithm>
#include "solution/AddTwoNumbers.cpp"

namespace X2 {

Solution s;

ListNode *fromInt(const int value) {
  std::string literal = std::to_string(value);
  std::vector<int> temp(literal.size());
  std::transform(literal.rbegin(), literal.rend(), temp.begin(), [](char n) {
    return n - '0';
  });
  return ListNode::build(temp);
}

int toInt(const ListNode *nums) {
  int value = 0;
  int base = 1;
  while (nums != nullptr) {
    value += nums->val * base;
    base *= 10;
    nums = nums->next;
  }
  return value;
}

#define TEST_ADD(a, b, c) \
  EXPECT_EQ(toInt(s.addTwoNumbers(fromInt(a), fromInt(b))), c)

#define TEST_LITERAL(value) \
  do { \
    ListNode *xs = fromInt(value); \
    EXPECT_EQ(toInt(xs), value); \
    ListNode::release(xs); \
  } while(0)

TEST(AddTwoNumbers, Utilies) {
  TEST_LITERAL(100);
  for (int i = 0; i < 1000; i++) {
    int value = abs(rand()) % 10000;
    TEST_LITERAL(value);
  }
}

TEST(AddTwoNumbers, Functionialty) {
  TEST_ADD(1, 2,  3);
  TEST_ADD(0, 99, 99);
  TEST_ADD(1, 99, 100);
}

}