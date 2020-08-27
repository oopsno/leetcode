/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// @lc code=start
#include <cstdlib>
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
