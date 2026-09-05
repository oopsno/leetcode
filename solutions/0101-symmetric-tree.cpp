/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

#include "leetcode/tree-node.h"

// @lc code=start
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
      return left->val == right->val and
             isSymmetric(left->left, right->right) and
             isSymmetric(left->right, right->left);
    } else {
      return left == right;
    }
  }
};
// @lc code=end

#include <doctest/doctest.h>

TEST_CASE("0101") {
  auto yes = stringToTreeNode("[1,2,2,3,4,4,3]");
  REQUIRE(Solution().isSymmetric(yes));
  auto no = stringToTreeNode("[1,2,2,null,3,null,3]");
  REQUIRE_FALSE(Solution().isSymmetric(no));
}
