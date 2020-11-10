/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>

enum State { UNKNONW = 0, YES = 1, NO = -1 };

template <typename Element>
struct matrix2d {
  matrix2d(size_t width, size_t height, Element default_value) {
    auto row = std::vector<Element>(width, default_value);
    storage = std::vector<std::vector<Element>>(height, row);
  }

  std::vector<std::vector<Element>> storage;

  Element &at(size_t y, size_t x) { return storage[y][x]; }
  const Element &at(size_t y, size_t x) const { return storage[y][x]; }

  void debug() const noexcept {
    for (const auto& row : storage) {
      for (const auto element : row) {
        std::cout << element << " ";
      }
      std::cout << std::endl;
    }
  }
};

class Solution {
  bool check(matrix2d<State> &mat, const std::string &s1, const std::string &s2,
             const std::string &s3) {
    int z = -1;
    mat.at(0, 0) = YES; // 初始状态为 YES
    // mat(Y, X) -> s1[:X], s2[:Y] <-> s3[:X + Y]
    for (int c = 0; c < s1.size(); ++ c) {
      mat.at(0, c + 1) = (mat.at(0, c) == YES and s1[c] == s3[c]) ? YES : NO;
    }
    for (int c = 0; c < s2.size(); ++ c) {
      mat.at(c + 1, 0) = (mat.at(c, 0) == YES and s2[c] == s3[c]) ? YES : NO;
    }
    for (int y = 1; y <= s2.size(); ++y) {
      for (int x = 1; x <= s1.size(); ++x) {
        const char next_target = s3[x + y - 1];
        const bool s1_s2 = mat.at(y - 1, x) == YES and next_target == s2[y - 1];
        const bool s2_s1 = mat.at(y, x - 1) == YES and next_target == s1[x - 1];
        mat.at(y, x) = s1_s2 or s2_s1 ? YES : NO;
      }
    }
    return mat.at(s2.size(), s1.size()) == YES;
  }

public:
  bool isInterleave(std::string s1, std::string s2, std::string s3) {
    // 根据长度快速否决
    if (s1.size() + s2.size() != s3.size()) {
      return false;
    }
    if (s1.empty()) {
      return s2 == s3;
    }
    if (s2.empty()) {
      return s1 == s3;
    }
    // 开始 DP
    matrix2d<State> mat(s1.size() + 1, s2.size() + 1, UNKNONW);
    return check(mat, s1, s2, s3);
  }
};
// @lc code=end

int main() {
  return 0;
}