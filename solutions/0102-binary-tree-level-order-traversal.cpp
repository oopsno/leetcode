/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

#include "leetcode/runner.h"
#include "leetcode/tree-node.h"

// @lc code=start
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    std::vector<std::vector<int>> xs;
    levelOrderImpl(root, xs, 1);
    return xs;
  }

private:
  void levelOrderImpl(TreeNode *root, std::vector<std::vector<int>> &xs,
                      int level) {
    if (root != nullptr) {
      while (xs.size() < level) {
        xs.emplace_back();
      }
      xs[level - 1].push_back(root->val);
      levelOrderImpl(root->left, xs, level + 1);
      levelOrderImpl(root->right, xs, level + 1);
    }
  }
};
// @lc code=end

#include <doctest/doctest.h>

TEST_CASE("0102") {
  auto f = Runner(102, &Solution::levelOrder);
  using T = std::vector<std::vector<int>>;
  SUBCASE("examples 1") {
    auto tree = stringToTreeNode("[3,9,20,null,null,15,7]");
    auto traversal = f(tree);
    REQUIRE_EQ(traversal, T({{3}, {9, 20}, {15, 7}}));
  }
  SUBCASE("example 2") {
    auto tree = stringToTreeNode("[1]");
    auto traversal = f(tree);
    REQUIRE_EQ(traversal, (T{{1}}));
  }
  SUBCASE("example 3") {
    auto tree = stringToTreeNode("[]");
    auto traversal = f(tree);
    REQUIRE(traversal.empty());
  }
}
