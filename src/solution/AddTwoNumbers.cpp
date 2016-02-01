#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X2 {
#endif

class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *current = &handler;
    int x, r = 0;
    while (l1 != nullptr && l2 != nullptr) {
      x = l1->val + l2->val + r;
      if (x < 10) {
        current->next = new ListNode(x);
        r = 0;
      } else {
        current->next = new ListNode(x - 10);
        r = 1;
      }
      current = current->next;
      l1 = l1->next;
      l2 = l2->next;
    }
    ListNode *rest = l1 != nullptr ? l1 : l2;
    while (rest != nullptr) {
      x = rest->val + r;
      if (x < 10) {
        current->next = new ListNode(x);
        r = 0;
      } else {
        r = 1;
        current->next = new ListNode(x - 10);
      }
      current = current->next;
      rest = rest->next;
    }
    if (r != 0) {
      current->next = new ListNode(1);
    }
    return handler.next;
  }
 private:
  ListNode handler = 0;
};

#if (defined(OFFLINE))
}
#endif