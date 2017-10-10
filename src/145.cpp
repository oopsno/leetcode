/**
 * 144. Binary Tree Postorder Traversal
 */

#include <vector>
#include "leetcode.hpp"

using TreeNode = LeetCode::TreeNode<int>;

class Solution {
 public:
  std::vector<int> postorderTraversal(TreeNode* root) {
    std::vector<int> xs;
    postorderTraversal(root, xs);
    return xs;
  }

  void postorderTraversal(TreeNode *root, std::vector<int> &xs) {
    if (root != nullptr) {
      postorderTraversal(root->left, xs);
      postorderTraversal(root->right, xs);
      xs.push_back(root->val);
    }
  }
};

#include <gtest/gtest.h>

TEST(BinaryTreeTraversal, Postorder) {
  auto tree = new TreeNode(2, new TreeNode(1), new TreeNode(3));
  ASSERT_EQ(Solution().postorderTraversal(tree), (std::vector<int>{1, 3, 2}));
  TreeNode::release(tree);
}
