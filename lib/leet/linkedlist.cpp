#include <vector>
#include "leet/structure.hpp"

ListNode::ListNode(std::initializer_list<int> elements) {
  if (elements.size() == 0) {
    throw std::out_of_range("Cannot initialize an empty LinkedList");
  }
  ListNode *current = nullptr;
  for (int element : elements) {
    if (current == nullptr) {
      val = element;
      current = this;
    } else {
      current->next = new ListNode(element);
      current = current->next;
    }
  }
}

ListNode *ListNode::build(const std::vector<int> &elements) {
  ListNode *head = nullptr;
  ListNode *current = head;
  if (elements.size() == 0) {
    return head;
  }
  for (int element : elements) {
    if (head == nullptr) {
      head = new ListNode(element);
      current = head;
    } else {
      current->next = new ListNode(element);
      current = current->next;
    }
  }
  return head;
}

ListNode::vec_t *ListNode::dump() const {
  vec_t *vec = new vec_t();
  const ListNode *list = this;
  do {
    vec->push_back(list->val);
    list = list->next;
  } while (list != nullptr);
  return vec;
}

size_t ListNode::size() const {
  size_t size = 1;
  const ListNode *cursor = this->next;
  while (cursor != nullptr) {
    size += 1;
    cursor = cursor->next;
  }
  return size;
}

int ListNode::operator[](const int index) {
  /* bound check */
  size_t length = this->size();
  /* revert indexing */
  int cnt = index;
  if (index < 0) {
    cnt += length;
  }
  if (cnt >= length) {
    throw std::out_of_range("LinkedList element access index over range.");
  }
  ListNode *cursor = this;
  for (int i = 0; i < cnt; i++) {
    cursor = cursor->next;
  }
  return cursor->val;
}
