/**
 * 100. Same Tree
 */

#include "leetcode.hpp"

using TreeNode = LeetCode::TreeNode<int>;

class Solution {
 public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == q) {
      return true;
    }
    if (p == nullptr or q == nullptr) {
      return false;
    }
    return p->val == q->val and isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
  }
};

#include <gtest/gtest.h>

TEST(BinaryTreeIsSame, Testcases) {
  using Tree = LeetCode::Tree<int>;
  auto x = Tree{1, 2, 3};
  auto y = Tree{1, 2, 3};
  ASSERT_TRUE(Solution().isSameTree(x, y));
  ASSERT_TRUE(Solution().isSameTree(x, x));
  ASSERT_TRUE(Solution().isSameTree(nullptr, nullptr));
  ASSERT_FALSE(Solution().isSameTree(nullptr, y));
  ASSERT_FALSE(Solution().isSameTree(x, nullptr));
}