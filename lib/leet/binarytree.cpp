#include "leet/structure.hpp"
#include <string>

const std::string sharp("#");

static inline int left(int root) {
  return root + root;
}

static inline int right(int root) {
  return left(root) + 1;
}

static void build_binary_tree(TreeNode *root, const int root_i, std::vector<std::string> &nodes) {
  int left_i = left(root_i), right_i = right(root_i);
  int limit = (const int) nodes.size();
  if (left_i < limit) {
    const std::string &left_t = nodes[left_i];
    if (left_t != sharp) {
      root->left = new TreeNode(std::stoi(left_t));
      build_binary_tree(root->left, left_i, nodes);
    } else {
      nodes.insert(nodes.begin() + right_i + 1, 2, "#");
      limit += 2;
    }
  }
  if (right_i < limit) {
    const std::string &right_t = nodes[right_i];
    if (right_t != sharp) {
      root->right = new TreeNode(std::stoi(right_t));
      build_binary_tree(root->right, right_i, nodes);
    }
  }
}

TreeNode *TreeNode::build(const std::string &serialized) {
  // remove spaces
  std::string s;
  for (char c : serialized) {
    if (not std::isspace(c)) {
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
  // tokenize
  std::vector<std::string> nodes = {"$"};
  char *ss = new char[length - 1];
  stpncpy(ss, s.c_str() + 1, length - 2);
  ss[length - 2] = 0;
  char *c_node = std::strtok(ss, ",");
  int counter = 0;
  while (c_node != nullptr) {
    counter += 1;
    const std::string token = c_node;
    nodes.push_back(token);

    c_node = strtok(nullptr, ",");
  }
  delete[](ss);
  // copy to tree
  int root_i = 1;
  TreeNode *root = new TreeNode(std::stoi(nodes[root_i]));
  build_binary_tree(root, root_i, nodes);
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

