/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

#include "leetcode/list-node.h"

// @lc code=start
#include <cstdlib>
#include <initializer_list>
class Solution {
private:
  static ListNode *push_back(ListNode **head, ListNode *node,
                             int value) noexcept {
    if (node == nullptr) {
      *head = new ListNode(value);
      return *head;
    } else {
      node->next = new ListNode(value);
      return node->next;
    }
  }

public:
  ListNode *addTwoNumbers(ListNode *lhs, ListNode *rhs) const noexcept {
    int carry = 0;
    ListNode *sum = nullptr, *head = nullptr;
    while (lhs != nullptr and rhs != nullptr) {
      const auto r = std::div(lhs->val + rhs->val + carry, 10);
      carry = r.quot;
      sum = push_back(&head, sum, r.rem);
      lhs = lhs->next;
      rhs = rhs->next;
    }
    while (lhs != nullptr) {
      const auto r = std::div(lhs->val + carry, 10);
      carry = r.quot;
      sum = push_back(&head, sum, r.rem);
      lhs = lhs->next;
    }
    while (rhs != nullptr) {
      const auto r = std::div(rhs->val + carry, 10);
      carry = r.quot;
      sum = push_back(&head, sum, r.rem);
      rhs = rhs->next;
    }
    if (carry != 0) {
      sum = push_back(&head, sum, carry);
    }
    return head;
  }
};
// @lc code=end

#include <doctest/doctest.h>

static bool run(std::initializer_list<int> lhs, std::initializer_list<int> rhs,
                std::initializer_list<int> expected) {
  Solution solution;
  auto lhs_list = makeListFrom(lhs);
  auto rhs_list = makeListFrom(rhs);
  auto expected_list = makeListFrom(expected);
  auto actual_list = solution.addTwoNumbers(lhs_list, rhs_list);
  return compareListNode(actual_list, expected_list);
}

TEST_CASE("0002") {
  REQUIRE(run({2, 4, 3}, {5, 6, 4}, {7, 0, 8}));
  REQUIRE(run({0}, {0}, {0}));
  REQUIRE(run({9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9}, {8, 9, 9, 9, 0, 0, 0, 1}));
}