#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X129 {
#endif

class Solution {
 public:
  int sumNumbers(const TreeNode *root, const int sum = 0) {
    if (root == nullptr) {
      return sum;
    }
    const int current = sum * 10 + root->val;
    const bool has_left = root->left != nullptr;
    const bool has_right = root->right != nullptr;
    if (has_left && has_right) {
      return sumNumbers(root->left, current) + sumNumbers(root->right, current);
    } else if (has_left) {
      return sumNumbers(root->left, current);
    } else if (has_right) {
      return sumNumbers(root->right, current);
    } else {
      return current;
    }
  }
};

#if (defined(OFFLINE))
}
#endif