/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
 */

#include "leetcode/tree-node.h"

namespace {
// @lc code=start

enum class State {
  NO_CAMERA,
  HAS_CAMERA,
  COVERED_BY_NABOR,
};

struct Context {
  int num_cameras = 0;
};

class Solution {
private:
  int result = 0;

  State dfs(TreeNode *node, Context& ctx) {
    if (node == nullptr) {
      return State::COVERED_BY_NABOR;
    }
    auto lhs = dfs(node->left, ctx);
    auto rhs = dfs(node->right, ctx);
    if (lhs == State::NO_CAMERA || rhs == State::NO_CAMERA) {
      ctx.num_cameras += 1;
      return State::HAS_CAMERA;
    } else if (lhs == State::HAS_CAMERA || rhs == State::HAS_CAMERA) {
      return State::COVERED_BY_NABOR;
    } else {
      return State::NO_CAMERA;
    }
  }

public:
  int minCameraCover(TreeNode *root) {
    Context ctx;
    if (dfs(root, ctx) == State::NO_CAMERA) {
      ctx.num_cameras += 1;
    }
    return ctx.num_cameras;
  }
};
// @lc code=end
}

#include <doctest/doctest.h>

TEST_CASE("0968") {
  SUBCASE("Example 1") {
    auto root = stringToTreeNode("[0,0,null,0,0]");
    REQUIRE_EQ(Solution().minCameraCover(root), 1);
  }
  SUBCASE("Example 2") {
    auto root = stringToTreeNode("[0,0,null,0,null,0,null,null,0]");
    REQUIRE_EQ(Solution().minCameraCover(root), 2);
  }
}
