#include "leetcode.hpp"

GTEST_TEST(Tree, Build) {
  auto x = Tree{1, 2, 3, std::nullopt, 4};
  // 1st level
  ASSERT_EQ(x->val, 1);
  // 2nd level
  ASSERT_EQ(x->left->val, 2);
  ASSERT_EQ(x->right->val, 3);
  ASSERT_TRUE(x->right->is_leaf());
  // 3rd level
  ASSERT_EQ(x->left->left, nullptr);
  ASSERT_EQ(x->left->right->val, 4);
  ASSERT_TRUE(x->left->right->is_leaf());
}

GTEST_TEST(List, Build) {
  auto xs = List{1, 2, 3};
  ASSERT_EQ(ListNode::size(xs), 3);
  ASSERT_EQ(xs.to_list(), (std::vector<int>{1, 2, 3}));
}
