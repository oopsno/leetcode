/*
 * @lc app=leetcode.cn id=381 lang=cpp
 *
 * [381] O(1) 时间插入、删除和获取随机元素 - 允许重复
 */

#include <unordered_map>
#include <unordered_set>
#include <vector>

// @lc code=start
class RandomizedCollection {
 private:
  std::vector<int> elements;
  std::unordered_map<int, std::unordered_set<size_t>> indices;

 public:
  /** Initialize your data structure here. */
  RandomizedCollection() = default;

  /** Inserts a value to the collection. Returns true if the collection did not
   * already contain the specified element. */
  bool insert(int val) {
    elements.push_back(val);
    indices[val].insert(elements.size() - 1);
    return indices[val].size() == 1;
  }

  /** Removes a value from the collection. Returns true if the collection
   * contained the specified element. */
  bool remove(int val) {
    if (elements.empty() or
        std::as_const(indices).find(val) == indices.cend()) {
      return false;
    } else {
      const size_t index = *indices[val].cbegin();
      const int replacement = elements.back();
      elements[index] = replacement;
      indices[val].erase(index);
      indices[replacement].erase(elements.size() - 1);
      if (index + 1 < elements.size()) {
        indices[replacement].insert(index);
      }
      if (indices[val].empty()) {
        indices.erase(val);
      }
      elements.pop_back();
      return true;
    }
  }

  /** Get a random element from the collection. */
  int getRandom() const { return elements[rand() % elements.size()]; }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
