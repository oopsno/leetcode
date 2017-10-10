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
  using Tree = LeetCode::Tree<int>;
  auto tree = Tree{2, 1, 3};
  ASSERT_EQ(Solution().postorderTraversal(tree), (std::vector<int>{1, 3, 2}));
}
