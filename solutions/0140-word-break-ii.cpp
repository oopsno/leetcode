/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II / Word Bread II
 * Given a string `s` and a dictionary of strings `wordDict`, add spaces in s to
 * construct a sentence where each word is a valid dictionary word.
 * Return all such possible sentences in any order.
 * Note that the same word in the dictionary may be reused multiple times
 * in the segmentation.
 */

#include <cstddef>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace {
// @lc code=start
class Solution {
public:
  using Memory = std::unordered_map<size_t, std::vector<std::string>>;
  using Dictionary = std::unordered_set<std::string>;
  void backtrack(const std::string &s, size_t index, Memory &memory,
                 const Dictionary &dictionary) {
    if (memory.contains(index)) {
      return;
    }
    if (index == s.size()) {
      memory[index] = {""};
      return;
    }
    memory[index] = {};
    for (size_t i = index + 1; i <= s.size(); ++i) {
      const auto word = s.substr(index, i - index);
      if (dictionary.contains(word)) {
        backtrack(s, i, memory, dictionary);
        for (const auto &succ : memory[i]) {
          if (succ.empty()) {
            memory[index].push_back(word);
          } else {
            memory[index].push_back(word + " " + succ);
          }
        }
      }
    }
  }

  std::vector<std::string> wordBreak(std::string s,
                                     std::vector<std::string> &wordDict) {
    Memory memory;
    Dictionary dictionary(wordDict.begin(), wordDict.end());
    backtrack(s, 0, memory, dictionary);
    return memory[0];
  }
};
// @lc code=end
} // namespace

#include "leetcode/runner.h"
#include <algorithm>
#include <doctest/doctest.h>

TEST_CASE("0140") {
  auto f = Runner(140, &Solution::wordBreak);
  SUBCASE("example 1") {
    std::string text = "catsanddog";
    std::vector<std::string> dictionary{"cat", "cats", "and", "sand", "dog"};
    std::vector<std::string> expected{"cats and dog", "cat sand dog"};
    auto actual = f(text, dictionary);
    std::sort(actual.begin(), actual.end());
    std::sort(expected.begin(), expected.end());
    REQUIRE_EQ(actual, expected);
  }
  SUBCASE("example 2") {
    std::string text = "pineapplepenapple";
    std::vector<std::string> dictionary{"apple", "pen", "applepen", "pine",
                                        "pineapple"};
    std::vector<std::string> expected{
        "pine apple pen apple", "pineapple pen apple", "pine applepen apple"};
    auto actual = f(text, dictionary);
    std::sort(actual.begin(), actual.end());
    std::sort(expected.begin(), expected.end());
    REQUIRE_EQ(actual, expected);
  }
  SUBCASE("example 3") {
    std::string text = "catsandog";
    std::vector<std::string> dictionary{"cats", "dog", "sand", "and", "cat"};
    std::vector<std::string> expected{};
    auto actual = f(text, dictionary);
    std::sort(actual.begin(), actual.end());
    REQUIRE_EQ(actual, expected);
  }
}