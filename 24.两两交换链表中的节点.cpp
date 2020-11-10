/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
  ListNode* swapPairs(ListNode* head) {
    // 长度为 0 或 1 的链表不需要执行交换操作
    if (head == nullptr or head->next == nullptr) {
      return head;
    }
    ListNode *first = head, *second = head->next, *new_head = head->next;
    while (true) {
      // 将 1->2->3->4 调整为 2->1->3->4
      ListNode* third = second->next;
      second->next = first;
      first->next = third;
      // 如果剩余节点数不小于 2，准备下一次迭代
      if (third != nullptr and third->next != nullptr) {
        ListNode* forth = third->next;
        first->next = forth;
        first = third;
        second = forth;
      } else {
        break;
      }
    }
    return new_head;
  }
};
// @lc code=end
