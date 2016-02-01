#include <gtest/gtest.h>
#include "leet/structure.hpp"

TEST(LinkedList, Build) {
  std::vector<int> vec_empty = {};
  ListNode *list_empty = ListNode::build(vec_empty);
  std::vector<int> vec_elem = {0, 1, 2, 3};
  ListNode *list_elem = ListNode::build(vec_elem);

  EXPECT_EQ(list_empty, nullptr);
  EXPECT_NE(list_elem, nullptr);
  EXPECT_EQ(list_elem->size(), vec_elem.size());
  for (int i = 0; i < vec_elem.size(); ++i) {
    EXPECT_EQ(list_elem->operator[](i), vec_elem[i]);
  }
}

TEST(LinkedList, Construct) {
  std::initializer_list<int> elements = {0, 1, 2, 3};
  ListNode list = elements;
  ListNode *cursor = &list;

  EXPECT_EQ(list.size(), elements.size());
  for (int element : elements) {
    EXPECT_EQ(element, cursor->val);
    cursor = cursor->next;
  }
}

TEST(LinkedList, Access) {
  const int elements[] = {1, 2, 3, 4, 5, 6, 7, 8};
  ListNode list = {1, 2, 3, 4, 5, 6, 7, 8};
  const ssize_t elements_cnt = sizeof(elements) / sizeof(int);
  ListNode::vec_t *dumped = list.dump();

  EXPECT_EQ(elements_cnt, dumped->size());
  EXPECT_EQ(elements_cnt, list.size());
  for (int i = 0; i < elements_cnt; i++) {
    EXPECT_EQ(elements[i], dumped->at(i));
    EXPECT_EQ(elements[i], list[i]);
  }
}

