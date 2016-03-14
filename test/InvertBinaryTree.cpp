#include <gtest/gtest.h>
#include "solution/InvertBinaryTree.cpp"
namespace X226 {

Solution s;

TEST(InvertBinaryTree, Functionality) {
  TreeNode *raw = TreeNode::build("{4,2,7,1,3,6,9}");
  TreeNode *val = TreeNode::build("{4,7,2,9,6,3,1}");
  raw = s.invertTree(raw);
  EXPECT_TRUE(TreeNode::equal(raw, val));
}

}

