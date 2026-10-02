/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 */

#include <algorithm>
#include <limits>
#include <stack>

#include "leetcode/tree-node.h"

// @lc code=start
struct Status {
  int mimimum_abs_diff = std::numeric_limits<int>::max();
  TreeNode* prev = nullptr;
};

class Solution {
public:
  void visit(TreeNode *root, Status &status) {
    if (root == nullptr) {
      return;
    }
    visit(root->left, status);
    if (status.prev != nullptr) {
      status.mimimum_abs_diff = std::min(status.mimimum_abs_diff, root->val - status.prev->val);
    }
    status.prev = root;
    visit(root->right, status);
  }
  int getMinimumDifference(TreeNode *root) {
    Status status;
    visit(root, status);
    return status.mimimum_abs_diff;
  }
};
// @lc code=end

#include <doctest/doctest.h>

TEST_CASE("0530") {
  auto tree1 = stringToTreeNode("[4,2,6,1,3]");
  REQUIRE_EQ(Solution().getMinimumDifference(tree1), 1);
  auto tree2 = stringToTreeNode("[1,0,48,null,null,12,49]");
  REQUIRE_EQ(Solution().getMinimumDifference(tree2), 1);
}