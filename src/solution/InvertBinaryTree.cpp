#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X226 {
#endif

class Solution {
 public:
  static TreeNode *invertTree(TreeNode *root) {
    if (root != nullptr) {
      invertTree(root->left);
      invertTree(root->right);
      std::swap(root->left, root->right);
    }
    return root;
  }
};

#if (defined(OFFLINE))
}
#endif