/**
 * 104. Maximum Depth of Binary Tree
 */

#include "leetcode.hpp"
DESCRIPTION(104, "Maximum Depth of Binary Tree", Trees);

class Solution {
 public:
  int maxDepth(TreeNode *root) {
    return root == nullptr ? 0 : std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};

TEST(MaximumDepthOfBinaryTree, Cases) {
  auto empty = Tree{};
  ASSERT_EQ(s.maxDepth(empty), 0);
  auto singleton = Tree{42};
  ASSERT_EQ(s.maxDepth(singleton), 1);
  auto link = Tree{1, 2};
  ASSERT_EQ(s.maxDepth(link), 2);
  auto full = Tree{1, 2, 3};
  ASSERT_EQ(s.maxDepth(full), 2);
}
