/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */

#include "leetcode/tree-node.h"

// @lc code=start
#include <string>
#include <vector>

struct Context {
  std::vector<std::string> resutls;
  std::string trace;
};

class Solution {
private:
  void visit(TreeNode *root, Context &ctx) {
    if (root == nullptr) {
      return;
    }
    size_t pos = ctx.trace.size();
    if (ctx.trace.empty()) {
      ctx.trace += std::to_string(root->val);
    } else {
      ctx.trace += "->" + std::to_string(root->val);
    }
    if (root->left && root->right) {
      visit(root->left, ctx);
      visit(root->right, ctx);
    } else if (root->left) {
      visit(root->left, ctx);
    } else if (root->right) {
      visit(root->right, ctx);
    } else {
      ctx.resutls.push_back(ctx.trace);
    }
    ctx.trace.resize(pos);
  }

public:
  std::vector<std::string> binaryTreePaths(TreeNode *root) {
    Context ctx;
    visit(root, ctx);
    return ctx.resutls;
  }
};
// @lc code=end

#include <doctest/doctest.h>

TEST_CASE("0257") {
  SUBCASE("Example 1") {
    auto root = stringToTreeNode("[1,2,3,null,5]");
    auto result = Solution().binaryTreePaths(root);
    std::vector<std::string> expected = {"1->2->5", "1->3"};
    REQUIRE_EQ(result, expected);
  }
  SUBCASE("Example 2") {
    auto root = stringToTreeNode("[1]");
    auto result = Solution().binaryTreePaths(root);
    std::vector<std::string> expected = {"1"};
    REQUIRE_EQ(result, expected);
  }
}
