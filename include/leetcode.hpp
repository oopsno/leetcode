#pragma once

namespace LeetCode {

template<typename T>
struct ListNode {
  explicit ListNode(T x) : val(x), next(nullptr) {}

  bool equalTo(const ListNode *rhs) const {
    auto lhs = this;
    while (lhs != nullptr and rhs != nullptr) {
      if (lhs->val != rhs->val) {
        return false;
      }
      lhs = lhs->next;
      rhs = rhs->next;
    }
    return lhs == nullptr and rhs == nullptr;
  }

  T val;
  ListNode *next;
};

}

