#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X141 {
#endif

class Solution {
 public:
  bool hasCycle(const ListNode *head) {
    const ListNode *slow = head, *fast = head;
    while (fast && slow && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) {
        return true;
      }
    }
    return false;
  }
};

#if (defined(OFFLINE))
}
#endif