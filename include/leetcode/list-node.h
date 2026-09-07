#pragma once

#include <vector>

struct ListNode {
  explicit ListNode(int x) noexcept : val(x), next(nullptr) {}

  int val = 0;
  ListNode *next = nullptr;

  std::vector<int> to_vector() const {
    std::vector<int> result;
    const ListNode *node = this;
    while (node != nullptr) {
      result.push_back(node->val);
      node = node->next;
    }
    return result;
  }
};

template <std::ranges::common_range Range>
ListNode *makeListFrom(Range &&range) {
  ListNode *head = nullptr, *tail = nullptr;
  for (const auto &value : range) {
    if (head == nullptr) {
      head = new ListNode(value);
      tail = head;
    } else {
      tail->next = new ListNode(value);
      tail = tail->next;
    }
  }
  return head;
}

template <typename Element>
inline ListNode *makeListFrom(std::initializer_list<Element> numbers) {
  auto dup = std::vector(numbers);
  return makeListFrom(dup);
}

inline bool compareListNode(ListNode *lhs, ListNode *rhs) noexcept {
  bool equal = true;
  while (lhs != nullptr and rhs != nullptr) {
    if (lhs->val != rhs->val) {
      equal = false;
      break;
    }
    lhs = lhs->next;
    rhs = rhs->next;
  }
  if (lhs != nullptr or rhs != nullptr) {
    equal = false;
  }
  return equal;
}
