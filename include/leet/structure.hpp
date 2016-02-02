#ifndef LEETCODE_STRUCTURE_HPP
#define LEETCODE_STRUCTURE_HPP

#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) { }

  /* OFFLINE UILITIES */
  ListNode(std::initializer_list<int> elements);
  static ListNode *build(const std::vector<int> &elements);
  static void release(ListNode *list);
  typedef std::vector<int> vec_t;
  vec_t *dump() const;
  size_t size() const;
  int operator[](const int index);
};


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }

  /* OFFLINE UTILITIES */
  static TreeNode *build(const std::string &serialized);
  static bool equal(const TreeNode *lhs, const TreeNode *rhs);
  static size_t height(const TreeNode *root, const size_t current = 0);
};


#endif //LEETCODE_STRUCTURE_HPP
