/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */

#include "leetcode/tree-node.h"

// @lc code=start
#include <algorithm>

class Solution {
public:
  int maxDepth(TreeNode *root) {
    return root == nullptr
               ? 0
               : std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};
// @lc code=end

#include <doctest/doctest.h>

TEST_CASE("0104") {
  auto empty = stringToTreeNode("[]");
  REQUIRE_EQ(Solution().maxDepth(empty), 0);
  auto singleton = stringToTreeNode("[42]");
  REQUIRE_EQ(Solution().maxDepth(singleton), 1);
  auto link = stringToTreeNode("[1,2]");
  REQUIRE_EQ(Solution().maxDepth(link), 2);
  auto full = stringToTreeNode("[1,2,3]");
  REQUIRE_EQ(Solution().maxDepth(full), 2);
}
