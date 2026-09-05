/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 */

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
// @lc code=start
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) const noexcept {
    // 处理非法数据
    if (head == nullptr or n <= 0) {
      return nullptr;
    }
    // left 止步于倒数第 n+1，right 止步于倒数第 1
    ListNode *left = head, *right = head;
    // left 和 right 之间的间隔距离应为 n
    for (int distance = 0; distance < n; ++distance) {
        right = right->next;
    }
    // 如果此时 right 抵达尾部，则说明要删除的是链表头部
    if (right == nullptr) {
        return head->next;
    }
    while (right->next != nullptr) {
      left = left->next;
      right = right->next;
    }
    left->next = left->next->next;
    return head;
  }
};
// @lc code=end