/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 */

#include "leetcode/tree-node.h"

namespace {
// @lc code=start
struct Context {
  int accum = 0;
};

class Solution {
public:
  void visit(TreeNode *root, Context &ctx) {
    if (root == nullptr) {
      return;
    }
    visit(root->right, ctx);
    ctx.accum = root->val = ctx.accum + root->val;
    visit(root->left, ctx);
  }
  TreeNode *convertBST(TreeNode *root) {
    Context ctx;
    visit(root, ctx);
    return root;
  }
};
// @lc code=end
} // namespace

#include <doctest/doctest.h>

TEST_CASE("0538") {
  using std::operator""s;
  SUBCASE("Example 1") {
    auto root =
        stringToTreeNode("[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]");
    auto result = Solution().convertBST(root);
    auto expected =
        "[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]"s;
    REQUIRE_EQ(treeNodeToString(result), expected);
  }
  SUBCASE("Example 2") {
    auto root = stringToTreeNode("[0,null,1]");
    auto result = Solution().convertBST(root);
    auto expected = "[1,null,1]"s;
    REQUIRE_EQ(treeNodeToString(result), expected);
  }
  SUBCASE("Example 3") {
    auto root = stringToTreeNode("[1,0,2]");
    auto result = Solution().convertBST(root);
    auto expected = stringToTreeNode("[3,3,2]");
    REQUIRE_EQ(treeNodeToString(result), treeNodeToString(expected));
  }
  SUBCASE("Example 4") {
    auto root = stringToTreeNode("[3,2,4,1]");
    auto result = Solution().convertBST(root);
    auto expected = stringToTreeNode("[7,9,4,10]");
    REQUIRE_EQ(treeNodeToString(result), treeNodeToString(expected));
  }
}
