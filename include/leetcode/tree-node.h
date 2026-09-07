#pragma once

#include <optional>
#include <string_view>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

TreeNode *vectorToTreeNode(const std::vector<std::optional<int>> &vec);

std::vector<std::optional<int>> treeNodeToVector(TreeNode *node);

TreeNode *stringToTreeNode(std::string_view text);

std::string treeNodeToString(TreeNode *node);