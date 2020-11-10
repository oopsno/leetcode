/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

#include <vector>

class Node {
public:
  int val;
  std::vector<Node *> neighbors;

  Node() {
    val = 0;
    neighbors = std::vector<Node *>();
  }

  Node(int _val) {
    val = _val;
    neighbors = std::vector<Node *>();
  }

  Node(int _val, std::vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};
// @lc code=start

#include <algorithm>
#include <array>
#include <stack>

class Solution {
private:
  static Node *next(std::deque<Node *> &queue) noexcept {
    Node *ptr = queue.front();
    queue.pop_front();
    return ptr;
  }
  static Node *create_or_find_node(std::unordered_map<int, Node *> &nodes,
                                   int value) noexcept {
    auto it = nodes.find(value);
    if (it == nodes.end()) {
      Node *node = new Node(value);
      nodes[value] = node;
      return node;
    } else {
      return it->second;
    }
  }

public:
  Node *cloneGraph(Node *node) noexcept {
    // 跳过空输入
    if (node == nullptr) {
      return nullptr;
    }
    // 用于广度优先搜索的队列
    std::deque<Node *> queue{node};
    // 用于记录已访问节点的散列表
    std::unordered_set<int> visited;
    // 用于记录已克隆节点的散列表
    std::unordered_map<int, Node *> nodes;
    // 广度优先搜索
    while (not queue.empty()) {
      Node *current = next(queue);
      const int u = current->val;
      // 如果节点 u (current) 没有被克隆过
      if (visited.count(u) == 0) {
        // 克隆节点 u
        Node *clone = create_or_find_node(nodes, u);
        // 克隆节点 u 的邻居
        for (Node *neighbor : current->neighbors) {
          const int v = neighbor->val;
          clone->neighbors.push_back(create_or_find_node(nodes, v));
          queue.push_back(neighbor);
        }
        // 将节点 U 标记为已克隆
        visited.insert(u);
      }
    }
    // 返回从 1 号节点开始克隆的图
    return nodes[node->val];
  }
};
// @lc code=end
