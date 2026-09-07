#include <cassert>
#include <queue>
#include <string>

#include <nlohmann/json.hpp>

#include "leetcode/tree-node.h"

TreeNode *vectorToTreeNode(const std::vector<std::optional<int>> &vec) {
  if (vec.empty() || !vec[0].has_value()) {
    return nullptr;
  }

  TreeNode *root = new TreeNode(vec[0].value());
  std::queue<TreeNode *> nodeQueue;
  nodeQueue.push(root);

  size_t i = 1;
  while (!nodeQueue.empty() && i < vec.size()) {
    TreeNode *node = nodeQueue.front();
    nodeQueue.pop();

    if (i < vec.size() && vec[i].has_value()) {
      node->left = new TreeNode(vec[i].value());
      nodeQueue.push(node->left);
    }
    i++;

    if (i < vec.size() && vec[i].has_value()) {
      node->right = new TreeNode(vec[i].value());
      nodeQueue.push(node->right);
    }
    i++;
  }
  return root;
}

std::vector<std::optional<int>> treeNodeToVector(TreeNode *root) {
  if (root == nullptr) {
    return {};
  }

  std::vector<std::optional<int>> result;
  std::queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode *node = q.front();
    q.pop();

    if (node == nullptr) {
      result.push_back(std::nullopt);
      continue;
    }

    result.push_back(node->val);
    q.push(node->left);
    q.push(node->right);
  }

  while (!result.empty() && !result.back().has_value()) {
    result.pop_back();
  }

  return result;
}

std::string treeNodeToString(TreeNode *root) {
  nlohmann::json doc;
  doc = treeNodeToVector(root);
  return doc.dump();
}

TreeNode *stringToTreeNode(std::string_view input) {
  std::vector<std::optional<int>> data = nlohmann::json::parse(input);
  return vectorToTreeNode(data);
}