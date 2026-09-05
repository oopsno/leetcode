/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

/**
 * Definition for a Node.
 */
class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

#include <algorithm>
#include <deque>

// @lc code=start
class Solution {
 public:
  Node* connect(Node* root) const noexcept {
    if (root == nullptr) {
      return nullptr;
    }
    Node* left = root;
    std::deque<Node*> current{root}, next;
    while (not current.empty()) {
      left = current.front();
      current.pop_front();
      if (left->left != nullptr) {
        next.push_back(left->left);
        next.push_back(left->right);
      }
      if (current.empty()) {
        std::swap(current, next);
      } else {
        left->next = current.front();
      }
    }
    return root;
  }
};
// @lc code=end
