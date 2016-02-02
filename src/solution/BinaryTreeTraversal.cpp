#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X94 {
#endif

class Solution {
 public:
  std::vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> trace;
    inorder(trace, root);
    return trace;
  }
 private:
  void inorder(std::vector<int> &trace, TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    inorder(trace, root->left);
    trace.push_back(root->val);
    inorder(trace, root->right);
  }
};

#if (defined(OFFLINE))
}
#endif


#if (defined(OFFLINE))
namespace X144 {
#endif

class Solution {
 public:
  std::vector<int> preorderTraversal(TreeNode *root) {
    std::vector<int> trace;
    preorde(trace, root);
    return trace;
  }
 private:
  void preorde(std::vector<int> &trace, TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    trace.push_back(root->val);
    preorde(trace, root->left);
    preorde(trace, root->right);
  }
};

#if (defined(OFFLINE))
}
#endif


#if (defined(OFFLINE))
namespace X145 {
#endif

class Solution {
 public:
  std::vector<int> postorderTraversal(TreeNode *root) {
    std::vector<int> trace;
    postorder(trace, root);
    return trace;
  }
 private:
  void postorder(std::vector<int> &trace, TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    postorder(trace, root->left);
    postorder(trace, root->right);
    trace.push_back(root->val);
  }
};

#if (defined(OFFLINE))
}
#endif