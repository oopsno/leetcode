#include <numeric>
#include <vector>

class Solution {
public:
  int maxSubarraySumCircular(std::vector<int> &nums) {
    std::vector<int> dp_max(nums.size());
    std::vector<int> dp_min(nums.size());
    int overall_sum = nums[0];
    int single_pass_min = 0;
    int single_pass_max = 0;
    bool has_positive = false;
    dp_max[0] = dp_min[0] = overall_sum = single_pass_max = single_pass_min =
        nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
      const int current = nums[i];
      dp_max[i] = std::max(current, current + dp_max[i - 1]);
      dp_min[i] = std::min(current, current + dp_min[i - 1]);
      overall_sum += current;
      single_pass_max = std::max(single_pass_max, dp_max[i]);
      single_pass_min = std::min(single_pass_min, dp_min[i]);
      has_positive |= current > 0;
    }
    if (!has_positive) {
      return single_pass_max;
    }
    return std::max(overall_sum - single_pass_min, single_pass_max);
  }
};
