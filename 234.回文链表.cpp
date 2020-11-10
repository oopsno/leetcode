/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// @lc code=start
class Solution {
 private:
  inline int length(ListNode* head) {
    int length = 0;
    while (head != nullptr) {
      head = head->next;
      length += 1;
    }
    return length;
  }
  inline ListNode* nth(ListNode* head, int n) {
    for (int i = 0; head != nullptr and i < n; ++i) {
      head = head->next;
    }
    return head;
  }
  inline bool equal(ListNode* lhs, ListNode* rhs) {
    while (lhs != nullptr and rhs != nullptr) {
      if (lhs->val != rhs->val) {
        return false;
      }
      lhs = lhs->next;
      rhs = rhs->next;
    }
    return lhs == nullptr and rhs == nullptr;
  }
  static ListNode* inplace_reverse(ListNode* node) {
    if (node == nullptr or node->next == nullptr) {
      return node;
    }
    ListNode *previous = nullptr, *current = node;
    while (current != nullptr) {
      ListNode* tmp = current->next;
      current->next = previous;
      previous = current;
      current = tmp;
    }
    return previous;
  }

 public:
  bool isPalindrome(ListNode* head) {
    const int n = length(head);
    if (n < 2) {
      return true;
    }
    bool result = false;
    // p 指向链表前半部分的末尾
    ListNode* p = nth(head, n / 2 - 1);
    ListNode *q = p->next, *rest = nullptr;
    // 切断前半部分
    p->next = nullptr;
    if (n % 2 == 1) {
      rest = inplace_reverse(q->next);
    } else {
      rest = inplace_reverse(q);
    }
    result = equal(head, rest);
    // 还原链表
    inplace_reverse(rest);
    p->next = q;
    return result;
  }
};

int main() {
    Solution s;
    ListNode *p = new ListNode(1, new ListNode(2, new ListNode(1)));
    s.isPalindrome(p);
    return 0;
}
// @lc code=end
