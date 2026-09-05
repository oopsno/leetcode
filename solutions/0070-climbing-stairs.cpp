#include <utility>

class Solution {
  public:
    int climbStairs(int n) {
        constexpr int S0 = 0;
        constexpr int S1 = 1;
        // shortcut for climbStairs(x) forall x <= 0
        if (n <= 0) {
            return S0;
        }
        // shortcut for climbStairs(1)
        if (n == 1) {
            return S1;
        }
        // initialize state for climbStairs(2)
        int s_minus_2 = S0;
        int s_minus_1 = S1;
        int s = s_minus_1 + s_minus_2;
        // accumulate till climbStairs(n)
        for (int step = 2; step <= n; ++ step) {
            s_minus_2 = std::exchange(s_minus_1, s);
            s = s_minus_1 +s_minus_2;
        }
        return s;
    }
};