/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

#include <algorithm>
#include <stack>
#include <tuple>

// @lc code=start
class MinStack {
 private:
  std::stack<std::tuple<int, int>> s;

 public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    if (s.empty()) {
      s.push({x, x});
    } else {
      const int minimal = std::get<0>(s.top());
      s.push({std::min(minimal, x), x});
    }
  }

  void pop() { s.pop(); }

  int top() { return std::get<1>(s.top()); }

  int getMin() { return std::get<0>(s.top()); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
