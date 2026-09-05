/**
 * 94. Binary Tree Inorder Traversal
 */

#include "leetcode/tree-node.h"
#include <stack>
#include <vector>

namespace recursive {

class Solution {
public:
  std::vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> xs;
    inorderTraversal(root, xs);
    return xs;
  }

  void inorderTraversal(TreeNode *root, std::vector<int> &xs) {
    if (root != nullptr) {
      inorderTraversal(root->left, xs);
      xs.push_back(root->val);
      inorderTraversal(root->right, xs);
    }
  }
};

} // namespace recursive

namespace stack {
class Solution {
public:
  std::vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> results;
    std::stack<TreeNode *> s;
    TreeNode *node = root;
    while (node != nullptr or not s.empty()) {
      while (node != nullptr) {
        s.push(node);
        node = node->left;
      }
      node = s.top();
      s.pop();
      results.emplace_back(node->val);
      node = node->right;
    }
    return results;
  }
};
} // namespace stack

#include <doctest/doctest.h>

TEST_CASE_TEMPLATE("0094", S, stack::Solution, recursive::Solution) {
  auto tree = stringToTreeNode("[2,1,3]");
  REQUIRE_EQ(S().inorderTraversal(tree), (std::vector<int>{1, 2, 3}));
}
