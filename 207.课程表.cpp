/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
private:
  using dag_t = std::unordered_map<int, std::unordered_set<int>>;

  static bool visit(dag_t &dag, int node, std::vector<int> &result, int &cursor,
                    std::unordered_set<int> &visited,
                    std::unordered_set<int> &temporary) {
    if (visited.count(node) == 0) {
      if (temporary.count(node) != 0) {
        return false;
      }
      temporary.insert(node);
      for (int succeed : dag[node]) {
        if (not visit(dag, succeed, result, cursor, visited, temporary)) {
          return false;
        }
      }
      temporary.erase(node);
      visited.insert(node);
      result[cursor--] = node;
    }
    return true;
  }

  static std::vector<int> topological_sort(int numCourses,
                                           dag_t &dag) noexcept {
    // 拓扑排序结果
    std::vector<int> result(numCourses, 0);
    int result_cursor = numCourses - 1;
    std::unordered_set<int> visited;
    std::unordered_set<int> temporary;
    while (result_cursor >= 0) {
      // 寻找第一个未被访问的节点
      int node = 0;
      for (; node < numCourses; ++node) {
        if (visited.count(node) == 0) {
          break;
        }
      }
      if (not visit(dag, node, result, result_cursor, visited, temporary)) {
        return {};
      }
    }
    return result;
  }
  static dag_t
  build_dag(const std::vector<std::vector<int>> &prerequisites) noexcept {
    dag_t dag;
    for (const auto &pair : prerequisites) {
      // 学习课程 pair[0] 之前需要完成课程 pair[1]
      dag[pair[1]].insert(pair[0]);
    }
    return dag;
  }

public:
  bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
    return findOrder(numCourses, prerequisites).size() == numCourses;
  }
  std::vector<int> findOrder(int numCourses,
                             std::vector<std::vector<int>> &prerequisites) {
    // 排除输入为空的情况
    if (numCourses == 0 or prerequisites.empty()) {
      return {};
    }
    // 建立 DAG
    dag_t dag = std::move(build_dag(prerequisites));
    // 计算任一可能的顺序
    return topological_sort(numCourses, dag);
  }
};
// @lc code=end
