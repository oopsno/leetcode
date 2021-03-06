/**
 * 94. Binary Tree Inorder Traversal
 */

#include <vector>
#include "leetcode.hpp"

using TreeNode = LeetCode::TreeNode<int>;

class Solution {
 public:
  std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> xs;
    inorderTraversal(root, xs);
    return xs;
  }

  void inorderTraversal(TreeNode *root, std::vector<int> &xs) {
    if (root != nullptr) {
      inorderTraversal(root->left, xs);
      xs.push_back(root->val);
      inorderTraversal(root->right, xs);
    }
  }
};

#include <gtest/gtest.h>

TEST(BinaryTreeTraversal, Inorder) {
  using Tree = LeetCode::Tree<int>;
  auto tree = Tree{2, 1, 3};
  ASSERT_EQ(Solution().inorderTraversal(tree), (std::vector<int>{1, 2, 3}));
}
