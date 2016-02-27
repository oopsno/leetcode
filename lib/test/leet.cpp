#include <gtest/gtest.h>
#include "leet/structure.hpp"
#include "leet/iterator.hpp"

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

TEST(BinaryTree, Equal) {
  EXPECT_TRUE(TreeNode::equal(nullptr, nullptr));
  EXPECT_TRUE(TreeNode::equal(new TreeNode(1), new TreeNode(1)));
}

TEST(BinaryTree, Height) {
  EXPECT_EQ(TreeNode::height(nullptr), 0);
  EXPECT_EQ(TreeNode::height(new TreeNode(0)), 1);
}

static TreeNode *build_1s23() {
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);
  return root;
}

static TreeNode *build_12s3s4() {
  TreeNode *root = new TreeNode(1);
  TreeNode *current = root;
  for (int i = 2; i <= 4; ++i) {
    current->left = new TreeNode(i);
    current = current->left;
  }
  return root;
}

static TreeNode *build_1s2s3s4() {
  TreeNode *root = new TreeNode(1);
  TreeNode *current = root;
  for (int i = 2; i <= 4; ++i) {
    current->right = new TreeNode(i);
    current = current->right;
  }
  return root;
}


TEST(BinaryTree, Build) {
  EXPECT_EQ(TreeNode::build("{}"), nullptr);
  EXPECT_TRUE(TreeNode::equal(TreeNode::build("{1}"), new TreeNode(1)));
  EXPECT_TRUE(TreeNode::equal(TreeNode::build("{1,#,2,3}"), build_1s23()));
  EXPECT_TRUE(TreeNode::equal(TreeNode::build("{1,2,#,3,#,4}"), build_12s3s4()));
  EXPECT_TRUE(TreeNode::equal(TreeNode::build("{1,#,2,#,3,#,4}"), build_1s2s3s4()));
  EXPECT_THROW(TreeNode::build(""), std::invalid_argument);
}

TEST(Iterator, Construct) {
  const std::vector<int> elements{0, 1};
  Iterator first = elements;
  EXPECT_TRUE(first.hasNext());
  EXPECT_EQ(first.next(), elements[0]);
  Iterator second = first;
  EXPECT_TRUE(second.hasNext());
  EXPECT_EQ(second.next(), elements[1]);
  EXPECT_FALSE(second.hasNext());
  EXPECT_TRUE(first.hasNext());
  EXPECT_EQ(first.next(), elements[1]);
  EXPECT_FALSE(first.hasNext());
}

TEST(Iterator, Iteration) {
  const std::vector<int> elements{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  Iterator it = elements;
  std::vector<int> duplication(elements.size());
  std::generate(duplication.begin(), duplication.end(), [&]() {
    return it.next();
  });
  EXPECT_EQ(elements, duplication);
  EXPECT_FALSE(it.hasNext());
}
