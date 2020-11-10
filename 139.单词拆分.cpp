/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

#include <algorithm>
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
    size_t offset = 0;
    while (offset < word.size()) {
      const char c = word[offset++];
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
  bool wordBreak(const std::string s, std::vector<std::string>& wordDict) {
    if (s.empty() or wordDict.empty()) {
      // 该行为未定义
      return false;
    }
    // 构建字典树
    Trie* trie = new Trie();
    int longest = std::numeric_limits<int>::min();
    int shortest = std::numeric_limits<int>::max();
    for (const auto& word : wordDict) {
      if (word.empty() or word.size() > s.size()) {
        continue;
      }
      trie->add(word);
      longest = std::max(longest, int(word.size()));
      shortest = std::min(shortest, int(word.size()));
    }
    // 构建 DP
    std::vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    /**
     * 状态转移：
     * m[i] 表示 s[0, i) 串可由字典构建
     * 1. 若 m[i], m[i + 1] 需要重新匹配
     * 2. 否则，向前搜索每一个匹配，直到到达末端
     */
    for (int end = 1; end <= s.size(); ++end) {
      if (not dp[end]) {
        bool match = false;
        // 最近搜索位置
        const int last = std::max(0, end - shortest);
        for (int begin = std::max(0, end - longest);
             begin <= last and not match; ++begin) {
          if (dp[begin]) {
            match = trie->contains(s, begin, end);
          }
        }
        dp[end] = match;
      }
    }
    return dp.back();
  }
};
// @lc code=end

#include <iostream>

int main() {
  Solution s;
  std::string word =
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "aaaaaa";
  std::vector<std::string> dict{"a",         "aa",        "aaa",     "aaaa",
                                "aaaaa",     "aaaaaa",    "aaaaaaa", "aaaaaaaa",
                                "aaaaaaaaa", "aaaaaaaaaa"};
  std::cout << std::boolalpha << s.wordBreak(word, dict) << std::endl;
  return 0;
}