/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 */

#include "leetcode/list-node.h"
#include <algorithm>
#include <cstddef>
#include <fmt/chrono.h>
#include <utility>

namespace {
// @lc code=start
/**
 * Definition for singly-linked list.
 */
class Solution {
private:
  ListNode *reverse(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr != nullptr) {
      auto *next = std::exchange(curr->next, prev);
      prev = std::exchange(curr, next);
    }
    return prev;
  }

  ListNode *middleNode(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }

  void merge(ListNode *lhs, ListNode *rhs) {
    ListNode *l_cursor = lhs;
    ListNode *r_curosr = rhs;
    while (lhs != nullptr && rhs != nullptr) {
      l_cursor = lhs->next;
      r_curosr = rhs->next;
      lhs->next = rhs;
      lhs = l_cursor;
      rhs->next = lhs;
      rhs = r_curosr;
    }
  }

public:
  void reorderList(ListNode *head) {
    if (head == nullptr || head->next == nullptr ||
        head->next->next == nullptr) {
      return;
    }
    auto *mid = middleNode(head);
    ListNode *lhs = head;
    ListNode *rhs = std::exchange(mid->next, nullptr);
    rhs = reverse(rhs);
    merge(lhs, rhs);
  }
};
// @lc code=end
} // namespace

#include <doctest/doctest.h>

TEST_CASE("0143") {
  Solution s;
  SUBCASE("example 1") {
    auto list = makeListFrom(std::vector{1, 2, 3, 4});
    auto output = makeListFrom(std::vector{1, 4, 2, 3});
    s.reorderList(list);
    REQUIRE_EQ(list->to_vector(), output->to_vector());
  }
}