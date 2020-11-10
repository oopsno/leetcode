/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>

// @lc code=start
class Solution {
 private:
  size_t editDistance(const std::string& lhs, const std::string& rhs) noexcept {
    if (lhs.size() != rhs.size()) {
      return std::min(lhs.size(), rhs.size());
    }
    // 计算编辑距离
    size_t distance = 0;
    for (size_t i = 0; i < lhs.size(); ++i) {
      distance += size_t(lhs[i] != rhs[i]);
    }
    return distance;
  }

 public:
  int ladderLength(std::string beginWord, std::string endWord,
                   std::vector<std::string>& wordList) noexcept {
    // 确保 beginWord, endWord 均在 wordList 中
    size_t head = wordList.size(), tail = wordList.size();
    for (size_t i = 0; i < wordList.size(); ++i) {
      if (wordList[i] == beginWord) {
        head = i;
      }
      if (wordList[i] == endWord) {
        tail = i;
      }
    }
    if (tail == wordList.size()) {
      return 0;
    }
    if (head == wordList.size()) {
      wordList.push_back(beginWord);
    }
    // 建图 + 状态压缩
    std::unordered_map<std::string, size_t> mapping;
    std::vector<std::vector<size_t>> graph(wordList.size());
    for (size_t i = 0; i < wordList.size(); ++i) {
      for (size_t j = 0; j < wordList.size(); ++j) {
        if (editDistance(wordList[i], wordList[j]) == 1) {
          graph[i].insert(j);
          graph[j].insert(i);
        }
      }
    }
    // 计算最短路
    constexpr int maximum = std::numeric_limits<int>::max();
    std::vector<int> forwardDistance(graph.size(), maximum);
    std::vector<int> backwardDistance(graph.size(), maximum);
    forwardDistance[head] = 0;
    backwardDistance[tail] = 0;

    std::queue<size_t> forwardQueue{{head}}, backwardQueue{{tail}};
    while (not forwardQueue.empty() and not backwardQueue.empty()) {
      // 前向 BFS
      const size_t forward_steps = forwardQueue.size();
      for (size_t i = 0; i < forward_steps; ++i) {
        const size_t node = forwardQueue.front();
        forwardQueue.pop();
        if (backwardDistance[node] != maximum) {
          return 1 + (forwardDistance[node] + backwardDistance[node]) / 2;
        }
        for (size_t next_node : graph.at(node)) {
          if (forwardDistance[next_node] == maximum) {
            forwardDistance[next_node] = forwardDistance[node] + 1;
            forwardQueue.push(next_node);
          }
        }
      }

      // 反向 BFS
      const size_t backward_steps = backwardQueue.size();
      for (size_t i = 0; i < backward_steps; ++i) {
        const size_t node = backwardQueue.front();
        backwardQueue.pop();
        if (forwardDistance[node] != maximum) {
          return 1 + (forwardDistance[node] + backwardDistance[node]) / 2;
        }
        for (size_t next_node : graph.at(node)) {
          if (backwardDistance[next_node] == maximum) {
            backwardDistance[next_node] = backwardDistance[node] + 1;
            backwardQueue.push(next_node);
          }
        }
      }
    }
    return 0;
  }
};
// @lc code=end


int main() {
  Solution solution;
  std::string begin = "qa";
  std::string end = "sq";
  std::vector<std::string> words{
      "si", "go", "se", "cm", "so", "ph", "mt", "db", "mb", "sb", "kr", "ln",
      "tm", "le", "av", "sm", "ar", "ci", "ca", "br", "ti", "ba", "to", "ra",
      "fa", "yo", "ow", "sn", "ya", "cr", "po", "fe", "ho", "ma", "re", "or",
      "rn", "au", "ur", "rh", "sr", "tc", "lt", "lo", "as", "fr", "nb", "yb",
      "if", "pb", "ge", "th", "pm", "rb", "sh", "co", "ga", "li", "ha", "hz",
      "no", "bi", "di", "hi", "qa", "pi", "os", "uh", "wm", "an", "me", "mo",
      "na", "la", "st", "er", "sc", "ne", "mn", "mi", "am", "ex", "pt", "io",
      "be", "fm", "ta", "tb", "ni", "mr", "pa", "he", "lr", "sq", "ye"};
  std::cout << solution.ladderLength(begin, end, words) << std::endl;
  return 0;
}