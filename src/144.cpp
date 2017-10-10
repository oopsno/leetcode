/**
 * 144. Binary Tree Preorder Traversal
 */

#include <vector>
#include "leetcode.hpp"

using TreeNode = LeetCode::TreeNode<int>;

class Solution {
 public:
  std::vector<int> preorderTraversal(TreeNode* root) {
    std::vector<int> xs;
    preorderTraversal(root, xs);
    return xs;
  }

  void preorderTraversal(TreeNode *root, std::vector<int> &xs) {
    if (root != nullptr) {
      xs.push_back(root->val);
      preorderTraversal(root->left, xs);
      preorderTraversal(root->right, xs);
    }
  }
};

#include <gtest/gtest.h>

TEST(BinaryTreeTraversal, Preorder) {
  using Tree = LeetCode::Tree<int>;
  auto tree = Tree{2, 1, 3};
  ASSERT_EQ(Solution().preorderTraversal(tree), (std::vector<int>{2, 1, 3}));
}
