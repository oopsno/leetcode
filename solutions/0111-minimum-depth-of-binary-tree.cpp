/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

#include "leetcode/tree-node.h"

// @lc code=start
#include <algorithm>

class Solution {
public:
  int minDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    if (root->left != nullptr and root->right != nullptr) {
      return std::min(minDepth(root->left), minDepth(root->right)) + 1;
    }
    if (root->left != nullptr) {
      return minDepth(root->left) + 1;
    }
    if (root->right != nullptr) {
      return minDepth(root->right) + 1;
    }
    return 1;
  }
};
// @lc code=end

#include <doctest/doctest.h>

TEST_CASE("0111") {
  auto empty = stringToTreeNode("[]");
  REQUIRE_EQ(Solution().minDepth(empty), 0);
  auto singleton = stringToTreeNode("[42]");
  REQUIRE_EQ(Solution().minDepth(singleton), 1);
  auto link = stringToTreeNode("[1,2]");
  REQUIRE_EQ(Solution().minDepth(link), 2);
  auto full = stringToTreeNode("[1,2,3]");
  REQUIRE_EQ(Solution().minDepth(full), 2);
}
