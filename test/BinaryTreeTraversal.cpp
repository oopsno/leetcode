#include <gtest/gtest.h>
#include "solution/BinaryTreeTraversal.cpp"
typedef std::pair<std::string, std::vector<int>> case_t;

namespace X94 {

Solution s;

TEST(BinaryTreeTraversal, Inodrder) {
  std::vector<case_t> cases = {case_t("{1,#,2,3}", {1, 3, 2})};
  for (case_t c : cases) {
    EXPECT_EQ(s.inorderTraversal(TreeNode::build(c.first)), c.second);
  }
}

}


namespace X144 {

Solution s;

TEST(BinaryTreeTraversal, Preorder) {
  std::vector<case_t> cases = {case_t("{1,#,2,3}", {1, 2, 3})};
  for (case_t c : cases) {
    EXPECT_EQ(s.preorderTraversal(TreeNode::build(c.first)), c.second);
  }
}

}


namespace X145 {

Solution s;

TEST(BinaryTreeTraversal, Postorder) {
  std::vector<case_t> cases = {case_t("{1,#,2,3}", {3, 2, 1})};
  for (case_t c : cases) {
    EXPECT_EQ(s.postorderTraversal(TreeNode::build(c.first)), c.second);
  }
}

}
