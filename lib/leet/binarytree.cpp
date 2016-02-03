#include "leet/structure.hpp"
#include <string>
#include <queue>
#include <cstdlib>

const char *sharp = "#";


TreeNode *TreeNode::build(const std::string &serialized) {
  // filter
  std::string s;
  for (char c : serialized) {
    if (std::isdigit(c) or c == ',' or c == '{' or c == '}' or c == '#') {
      s.push_back(c);
    }
  }
  // validate input
  const size_t length = s.size();
  if (!(length >= 2 && s[0] == '{' && s[length - 1] == '}')) {
    throw std::invalid_argument("Bad Binary Tree Serialization");
  }
  // deal with empty tree
  if (length == 2 || (length == 3 && s[1] == '#')) {
    return nullptr;
  }
  // tokenize & parse
  std::queue<TreeNode *> queue;
  char *ss = new char[length - 1];
  std::strncpy(ss, s.c_str() + 1, length - 2);
  ss[length - 2] = 0;
  TreeNode *root = nullptr;
  for (char *n = std::strtok(ss, ","); n != nullptr; n = std::strtok(nullptr, ",")) {
    if (root == nullptr) {
      root = new TreeNode(std::atoi(n));
      queue.push(root);
      continue;
    }
    TreeNode *current = queue.front();
    queue.pop();
    if (std::strcmp(n, sharp) != 0) { // not '#'
      current->left = new TreeNode(std::atoi(n));
      queue.push(current->left);
    }
    n = std::strtok(nullptr, ",");
    if (n == nullptr) {
      break;
    }
    if (std::strcmp(n, sharp) != 0) { // not '#'
      current->right = new TreeNode(std::atoi(n));
      queue.push(current->right);
    }
  }
  delete[](ss);
  return root;
}


bool TreeNode::equal(const TreeNode *lhs, const TreeNode *rhs) {
  if (lhs == nullptr and rhs == nullptr) {
    return true;
  }
  if (lhs != nullptr and rhs != nullptr) {
    if (lhs->val == rhs->val) {
      return TreeNode::equal(lhs->left, rhs->left) and TreeNode::equal(lhs->right, rhs->right);
    } else {
      return false;
    }
  }
  return false;
}


size_t TreeNode::height(const TreeNode *root, const size_t current) {
  if (root == nullptr) {
    return current;
  } else {
    return std::max(height(root->left, current + 1), height(root->right, current + 1));
  }
}

