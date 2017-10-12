#include <gtest/gtest.h>
#include "leetcode.hpp"

TEST(Tree, Build) {
  using Tree = LeetCode::Tree<int>;
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
