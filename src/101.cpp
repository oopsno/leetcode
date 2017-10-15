/**
 * 101. Symmetric Tree
 */

#include "leetcode.hpp"
DESCRIPTION(101, "Symmetric Tree", Trees);

class Solution {
 public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) {
      return true;
    } else {
      return isSymmetric(root->left, root->right);
    }
  }
  bool isSymmetric(TreeNode *left, TreeNode *right) {
    if (left != nullptr and right != nullptr) {
      return left->val == right->val and isSymmetric(left->left, right->right) and isSymmetric(left->right, right->left);
    } else {
      return left == right;
    }
  }
};

TEST(SymmetricTree, Empty) {
  auto tree = Tree{};
  ASSERT_TRUE(s.isSymmetric(tree));
}

TEST(SymmetricTree, Example) {
  auto yes = Tree{1, 2, 2, 3, 4, 4, 3};
  ASSERT_TRUE(s.isSymmetric(yes));
  auto no = Tree{1, 2, 2, std::nullopt, 3, std::nullopt, 3};
  ASSERT_FALSE(s.isSymmetric(no));
}
