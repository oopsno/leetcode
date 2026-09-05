/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>

namespace rows {

class Solution {
public:
  std::string convert(std::string s, int numRows) {
    std::ostringstream os;
    std::vector<std::ostringstream> oss(numRows);
    int step = -1;
    for (int i = 0, r = 0; i < s.size(); ++i) {
      oss[r] << s[i];
      if (r == 0 || r == (numRows - 1)) {
        step = -step;
      }
      r += step;
    }
    for (int i = 0; i < numRows; ++i) {
      os << oss[i].str();
    }
    return os.str();
  }
};
} // namespace rows

namespace arith {
class Solution {
public:
  std::string convert(std::string s, int numRows) {
    // 处理无需折叠的情况
    if (numRows <= 1 || s.size() < numRows) {
      return s;
    }
    // (PAYPALISHIRING, 3)
    //  i, Row, Col,  j
    //  0,   0,   0,  0
    //  1,   1,   0,  4
    //  2,   2,   0, 11
    //  3,   1,   1,  5
    //  4,   0,   2,  1
    //  5,   1,   2,  6
    //  6,   2,   2, 12
    //  7,   1,   3,  7
    //  8,   0,   4,  2
    //  9,   1,   4,  8
    // 10,   2,   4, 13
    // 11,   1,   5,  9
    // 12,   2,   6,  3
    // 13,   1,   6, 10

    int period = 2 * numRows - 2;
    const auto [full_periods, rem] = std::div(s.size(), period);

    auto zigzag = [=](int i) {
      if (numRows == 1) {
        return i;
      }
      std::vector<int> len_row{full_periods + int(rem > 0)};
      for (int j = 1; j < numRows - 1; ++j) {
        len_row.push_back((2 * full_periods) + int(rem > j) + int(rem > period - j));
      }
      if (numRows > 1) {
        len_row.push_back(full_periods + int(rem > (numRows - 1)));
      }

      std::vector<int> prefix(numRows, 0);
      for (int r = 1; r < numRows; ++r) {
        prefix[r] = prefix[r - 1] + len_row[r - 1];
      }

      int pos, r;
      const auto [s, k] = std::div(i, period);
      if (k < numRows) {
        r = k;
        pos = (r == 0 || r == numRows - 1) ? s : 2 * s;
      } else {
        r = period - k;
        pos = 2 * s + 1;
      }
      return prefix[r] + pos;
    };

    std::string result(s.size(), ' ');
    for (int i = 0; i < s.size(); ++i) {
      int j = zigzag(i);
      result[j] = s[i];
    }
    return result;
  }
};

} // namespace arith

#include "leetcode/runner.h"
#include <doctest/doctest.h>

TEST_CASE_TEMPLATE("0006", S, rows::Solution, arith::Solution) {
  auto f = Runner(6, &S::convert);
  REQUIRE_EQ(f("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
  REQUIRE_EQ(f("PAYPALISHIRING", 4), "PINALSIGYAHRPI");
  REQUIRE_EQ(f("A", 1), "A");
}
// @lc code=end
