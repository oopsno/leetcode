/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 */

#include <algorithm>
#include <deque>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 */
class Solution {
 public:
  void reorderList(ListNode *head) const {
    // 长度不大于 2 的链表无需交换
    if (head == nullptr or head->next == nullptr or
        head->next->next == nullptr) {
      return;
    }
    std::deque<ListNode *> nodes;
    for (ListNode *cursor = head; cursor != nullptr; cursor = cursor->next) {
      nodes.push_back(cursor);
    }
    ListNode *last = nullptr;
    while (nodes.size() >= 2) {
      nodes.front()->next = nodes.back();
      if (last != nullptr) {
        last->next = nodes.front();
      }
      last = nodes.back();
      nodes.pop_front();
      nodes.pop_back();
    }
    if (not nodes.empty()) {
      last->next = nodes.front();
      nodes.front()->next = nullptr;
      nodes.clear();
    }
  }
};
// @lc code=end

ListNode *create(const std::vector<int> &xs) noexcept {
  ListNode *head = nullptr, *cursor = nullptr;
  for (int x : xs) {
    if (cursor == nullptr) {
      head = cursor = new ListNode(x);
    } else {
      cursor->next = new ListNode(x);
      cursor = cursor->next;
    }
  }
  return head;
}

ListNode *create(int begin, int end) noexcept {
  return begin > end ? nullptr : new ListNode(begin, create(begin + 1, end));
}

void destory(ListNode *head) {
    if (head != nullptr) {
        destory(head->next);
        delete head;
    }
}

int main() {
  Solution s;
  ListNode *five = create(1, 5);
  s.reorderList(five);
  destory(five);
  return 0;
}