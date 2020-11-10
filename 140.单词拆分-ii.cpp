/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

// @lc code=start
struct Trie {
  std::unordered_map<char, Trie*> tree;
  size_t endpoint = 0;

  void add(const std::string& word) noexcept {
    Trie* current = this;
    for (const char c : word) {
      if (current->tree.count(c) == 1) {
        current = current->tree.at(c);
      } else {
        current = current->tree[c] = new Trie();
      }
    }
    current->endpoint = word.size();
  }

  bool contains(const std::string& word, size_t begin,
                size_t end) const noexcept {
    const Trie* current = this;
    while (begin < end) {
      const char c = word[begin];
      if (current->tree.count(c) == 1) {
        current = current->tree.at(c);
        begin += 1;
      } else {
        return false;
      }
    }
    return current->endpoint != 0;
  }
};

class Solution {
 public:
  std::vector<std::string> wordBreak(std::string s,
                                     std::vector<std::string>& wordDict) {
    std::vector<std::string> results;
    if (s.empty() or wordDict.empty()) {
      return results;
    }
    // 构建字典树
    size_t longest = std::numeric_limits<size_t>::min();
    size_t shortest = std::numeric_limits<size_t>::max();
    Trie* trie = new Trie();
    for (const auto& word : wordDict) {
      if (word.empty() or word.size() > s.size()) {
        continue;
      }
      trie->add(word);
      longest = std::max(longest, word.size());
      shortest = std::min(shortest, word.size());
    }
    // 记忆化搜索
    std::unordered_map<size_t, std::vector<size_t>> mem;
    std::deque<size_t> heads{{0}};
    while (not heads.empty()) {
      const size_t begin = heads.front();
      heads.pop_front();

      // 如果这项搜索曾经执行过，读取缓存
      if (mem.count(begin) == 1) {
        const auto& next_steps = mem.at(begin);
        for (const size_t x : next_steps) {
          heads.push_back(x);
        }
        break;
      }

      // 否则执行搜索
      const Trie* current = trie;
      std::vector<size_t> next_steps;
      size_t cursor = begin;
      const size_t end = begin + longest;
      while (cursor < end) {
        const char c = s[cursor];
        if (current->tree.count(c) == 1) {
          current = current->tree.at(c);
          if (current->endpoint != 0) {
            next_steps.push_back(cursor + 1);
          }
          cursor += 1;
        }
      }
      if (not next_steps.empty() and next_steps.back() == s.size()) {
        std::cout << "Oh" << std::endl;
      }
      // 记录搜索结果
      mem[begin] = std::move(next_steps);
    }
    return results;
  }
};
// @lc code=end

int main() {
  Solution s;
  std::string text = "catsanddog";
  std::vector<std::string> dictionary{"cat", "cats", "and", "sand", "dog"};
  s.wordBreak(text, dictionary);
  return 0;
}