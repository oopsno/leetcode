/**
 * 62. Unique Paths
 */

#include <algorithm>
#include <array>

static const std::array<int, 46> primes
    {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109,
     113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};

class Solution {
 public:
  int uniquePaths(int m, int n) {
    std::array<int, primes.size()> xs{};
    const auto steps = m + n - 2, right = m - 1, down = n - 1;
    for (auto e = steps - right + 1; e <= steps; ++e) {
      modify(xs, e, +1);
    }
    for (auto e = 2; e <= right; ++e) {
      modify(xs, e, -1);
    }
    return to_int(xs);
  }

  template<size_t Size>
  inline void modify(std::array<int, Size> &xs, int x, int modifier) {
    auto i = 0;
    while (x > 1 and i < primes.size()) {
      const auto p = primes[i];
      const auto m = std::div(x, p);
      if (m.rem == 0) {
        x = m.quot;
        xs[i] += modifier;
      } else {
        i += 1;
      }
    }
  }

  template<size_t Size>
  int to_int(std::array<int, Size> &xs) {
    int result = 1;
    for (auto i = 0; i < xs.size(); ++i) {
      while (xs[i] != 0)
        if (xs[i] > 0) {
          result *= primes[i];
          xs[i] -= 1;
        } else {
          result /= primes[i];
          xs[i] += 1;
        }
    }
    return result;
  }
};

#include <gtest/gtest.h>

TEST(UniquePaths, Testcases) {
  Solution solution;
  using cases = std::vector<std::tuple<int, int, int>>;
  for (const auto [m, n, p] : cases{{4, 5, 35}, {100, 100, -2129403600}, {42, 42, 1711821992}, {3, 100, 5050}}) {
    ASSERT_EQ(solution.uniquePaths(m, n), p);
    ASSERT_EQ(solution.uniquePaths(n, m), p);
  }
  ASSERT_EQ(solution.uniquePaths(1, 3), 1);
  ASSERT_EQ(solution.uniquePaths(3, 1), 1);
}
