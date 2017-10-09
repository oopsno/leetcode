/**
 * 1. Two Sum
 */

#include <algorithm>
#include <vector>

struct Element {
  int value, position;
};

bool operator<(const Element lhs, const Element rhs) {
  return lhs.value < rhs.value;
}

class Solution {
 public:
  auto twoSum(const std::vector<int> &nums, int target) -> std::vector<int> {
    auto result = std::vector<int>{0, 0};
    auto xs = std::vector<Element>(nums.size());
    for (auto i = 0; i < nums.size(); ++i) {
      xs[i].position = i;
      xs[i].value = nums[i];
    }
    std::sort(xs.begin(), xs.end());
    const auto right = static_cast<int>(xs.size());
    for (auto i = 0; i < right; ++i) {
      const auto current = xs[i];
      const auto found = binary_search(xs, target - current.value, i + 1, right - 1);
      if (found >= 0) {
        result[0] = current.position;
        result[1] = xs[found].position;
        if (result[0] > result[1]) {
          std::swap(result[0], result[1]);
        }
        break;
      }
    }
    return result;
  }

  static int binary_search(const std::vector<Element> &xs, int value, int left, int right) {
    if (left > right) {
      return -1;
    }
    auto middle = (left + right) / 2;
    auto pivot = xs[middle].value;
    if (pivot == value) {
      return middle;
    } else if (pivot < value) {
      return binary_search(xs, value, middle + 1, right);
    } else {
      return binary_search(xs, value, left, middle - 1);
    }
  }
};

#include <gtest/gtest.h>

TEST(TwoSum, Testcase1) {
  auto solution = Solution();
  const std::vector<int> xs{3, 2, 4}, ys{1, 2};
  ASSERT_EQ(solution.twoSum(xs, 6), ys);
}

TEST(TwoSum, Testcase2) {
  auto solution = Solution();
  const std::vector<int> xs{0, 2, 4, 0}, ys{0, 3};
  ASSERT_EQ(solution.twoSum(xs, 0), ys);
}

TEST(TwoSum, Testcase3) {
  auto solution = Solution();
  const std::vector<int> xs{3, 3}, ys{0, 1};
  ASSERT_EQ(solution.twoSum(xs, 6), ys);
}
