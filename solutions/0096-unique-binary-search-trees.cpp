/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
  int numTrees(const int n) noexcept {
    // n < 0 则无意义，n >= 20 时整数溢出
    if (n < 0 or n >= 20) {
      return -1;
    }
    // 0 个或 1 个节点显然只能构造 1 种 BST
    // 即 f(0) = f(1) = 1
    int f[20] = {1, 1};
    // n 个节点时，取第 i 个节点为根节点，则左子树包含 i 个节点，右子树包含 n -
    // i - 1 个节点 即 f(n) = f(0)f(n - 1) + f(1)f(n - 2) + ... + f(n - 1)f(0)
    for (int k = 2; k <= n; ++k) {
      for (int i = 0; i < k; ++i) {
        f[k] += f[i] * f[k - i - 1];
      }
    }
    return f[n];
  }
};
// @lc code=end