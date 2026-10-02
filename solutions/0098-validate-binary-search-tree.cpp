/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

#include "leetcode/tree-node.h"
#include <cstdint>
#include <limits>
#include <utility>

namespace {
// @lc code=start
struct Context {
  // 上下界, 左开右开, 要小心传入节点本身就是 int 最大/小值
  int64_t upper_bound = std::numeric_limits<int64_t>::max();
  int64_t lower_bound = std::numeric_limits<int64_t>::min();
  // 合法性
  bool valid = true;
};

class Solution {
public:
  void visit(TreeNode *root, Context &ctx) {
    if (root == nullptr) {
      return;
    }
    auto upper = std::exchange(ctx.upper_bound, root->val);
    visit(root->left, ctx);
    ctx.upper_bound = upper;
    ctx.valid &= (ctx.lower_bound < root->val) && (root->val < ctx.upper_bound);
    // 失败立刻停止遍历
    if (!ctx.valid) {
      return;
    }
    auto lower = std::exchange(ctx.lower_bound, root->val);
    visit(root->right, ctx);
    ctx.lower_bound = lower;
  }
  bool isValidBST(TreeNode *root) {
    Context ctx;
    visit(root, ctx);
    return ctx.valid;
  }
};
// @lc code=end
} // namespace

#include <doctest/doctest.h>

TEST_CASE("0098") {
  auto t0 = stringToTreeNode("[2,1,3]");
  REQUIRE(Solution().isValidBST(t0));
  auto t1 = stringToTreeNode("[5,1,4,null,null,3,6]");
  REQUIRE_FALSE(Solution().isValidBST(t1));
  auto t2 = stringToTreeNode("[3,null,30,10,null,null,15,null,45]");
  REQUIRE_FALSE(Solution().isValidBST(t2));
  auto t3 = stringToTreeNode("[5,4,6,null,null,3,7]");
  REQUIRE_FALSE(Solution().isValidBST(t3));
  auto t4 = stringToTreeNode("[2147483647]");
  REQUIRE(Solution().isValidBST(t4));
  auto t5 = stringToTreeNode("[-2147483658]");
  REQUIRE(Solution().isValidBST(t5));
}
