/**
 * 2 - Add Two Numbers
 */

#include <cstdlib>
#include <cstdint>
#include "leetcode.hpp"

using ListNode = LeetCode::ListNode<int>;

class Solution {
 public:
  inline int digit(ListNode *node) {
    return node == nullptr ? 0 : node->val;
  }
  inline void step(ListNode *&node) {
    if (node != nullptr) {
      node = node->next;
    }
  }
  inline int pushDigit(ListNode *&head, int digit) {
    const auto x = std::div(digit, 10);
    head->next = new ListNode(x.rem);
    head = head->next;
    return x.quot;
  }
  ListNode *addTwoNumbers(ListNode *lhs, ListNode *rhs) {
    static auto root = ListNode(0);
    auto head = &root;
    int carry = 0;
    while (lhs != nullptr or rhs != nullptr or carry > 0) {
      carry = pushDigit(head, digit(lhs) + digit(rhs) + carry);
      step(lhs); step(rhs);
    }
    return root.next;
  }
};

struct Case {
  Case(int lhs, int rhs) {
    this->lhs = fromValue(lhs);
    this->rhs = fromValue(rhs);
    this->sum = fromValue(lhs + rhs);
  }

  template<typename Integer>
  ListNode *fromValue(Integer value) {
    static auto root = ListNode(0);
    auto head = &root;
    if (value == 0) {
      return new ListNode(0);
    }
    while (value > 0) {
      const auto d = std::div(value, 10);
      value = d.quot;
      head->next = new ListNode(d.rem);
      head = head->next;
    }
    return root.next;
  }

  ListNode *lhs, *rhs, *sum;
};

#include <catch.hpp>
TEST_CASE("Add Two Numbers") {
  auto solution = Solution();
  SECTION("case - 1") {
    const auto c = Case(342, 465);
    REQUIRE(solution.addTwoNumbers(c.lhs, c.rhs)->equalTo(c.sum));
    REQUIRE(solution.addTwoNumbers(c.rhs, c.lhs)->equalTo(c.sum));
  }
  SECTION("case - 2") {
    const auto c = Case(0, 19);
    REQUIRE(solution.addTwoNumbers(c.lhs, c.rhs)->equalTo(c.sum));
    REQUIRE(solution.addTwoNumbers(c.rhs, c.lhs)->equalTo(c.sum));
  }
  SECTION("case - 3") {
    const auto c = Case(1, 19);
    REQUIRE(solution.addTwoNumbers(c.lhs, c.rhs)->equalTo(c.sum));
    REQUIRE(solution.addTwoNumbers(c.rhs, c.lhs)->equalTo(c.sum));
  }
  SECTION("case - 4") {
    const auto c = Case(99, 999);
    REQUIRE(solution.addTwoNumbers(c.lhs, c.rhs)->equalTo(c.sum));
    REQUIRE(solution.addTwoNumbers(c.rhs, c.lhs)->equalTo(c.sum));
  }
  SECTION("case - 5") {
    const auto c = Case(999, 999);
    REQUIRE(solution.addTwoNumbers(c.lhs, c.rhs)->equalTo(c.sum));
    REQUIRE(solution.addTwoNumbers(c.rhs, c.lhs)->equalTo(c.sum));
  }
}