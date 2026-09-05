---
name: leetcode-solution
description: Create LeetCode solution files with problem description, code skeleton, and unit tests from problem ID
---

## What I do

Automatically generate complete LeetCode solution files (.cpp) that include:
- Problem description comments (docstring)
- Code skeleton with proper includes
- Unit tests using doctest framework

## When to use me

Use this skill when the user wants to create a new LeetCode solution file for a given problem ID. The user will provide a problem ID, and I will generate a complete solution file ready for implementation.

## Workflow

1. **Fetch problem details**: Run `uv tool run --from leetcode-local-cli lc get <PROBLEM_ID>` to get problem information
2. **Parse output**: Extract from the output:
   - Problem ID
   - Problem slug (English name, e.g., "two-sum")
   - Problem title (Chinese name, e.g., "两数之和")
   - Difficulty (Easy/Medium/Hard)
   - Tags (e.g., "Array", "Hash Table", "Tree")
   - Problem description with examples
3. **Determine headers**: Based on tags, include appropriate headers:
   - Tags containing "Linked List": `#include "leetcode/list-node.h"`
   - Tags containing "Tree", "Binary Tree", or "BST": `#include "leetcode/tree-node.h"`
   - Other tags: No special headers needed
4. **Generate solution file**: Create `solutions/<4-digit-id>-<slug>.cpp` with the structure below
5. **Regenerate CMakeLists.txt**: Run `python3 scripts/gen.py` to update the build system

## Output Format

Create file at `solutions/<PROBLEM_ID_PADDED>-<slug>.cpp`:

```cpp
/*
 * @lc app=leetcode.cn id=<PROBLEM_ID> lang=cpp
 *
 * [<PROBLEM_ID>] <TITLE>
 */

// Include headers based on tags (if needed)
// #include "leetcode/list-node.h"
// #include "leetcode/tree-node.h"

// @lc code=start
#include <vector>

class Solution {
public:
    // TODO: Implement solution here
};
// @lc code=end

#include "leetcode/runner.h"
#include <doctest/doctest.h>

TEST_CASE("<PROBLEM_ID_PADDED>") {
    // TODO: Add test cases based on examples
}
```

## Unit Test Generation Rules

Based on problem type, generate appropriate test cases:

### Simple functions (most problems)
Use `Runner` to wrap the solution method:
```cpp
TEST_CASE("0001") {
    auto f = Runner(1, &Solution::twoSum);
    REQUIRE_EQ(f({2, 7, 11, 15}, 9), std::vector{0, 1});
}
```

### Linked list problems
Use `makeListFrom` to create lists and `compareListNode` to compare results:
```cpp
TEST_CASE("0002") {
    Solution solution;
    auto lhs = makeListFrom({2, 4, 3});
    auto rhs = makeListFrom({5, 6, 4});
    auto expected = makeListFrom({7, 0, 8});
    auto result = solution.addTwoNumbers(lhs, rhs);
    REQUIRE(compareListNode(result, expected));
}
```

### Tree problems
Use `stringToTreeNode` to create trees from JSON-like strings:
```cpp
TEST_CASE("0104") {
    auto tree = stringToTreeNode("[3,9,20,null,null,15,7]");
    REQUIRE_EQ(Solution().maxDepth(tree), 3);
}
```

## Example

For problem 1 (Two Sum):
- ID: 1
- Slug: two-sum
- Title: 两数之和
- Tags: Array, Hash Table

Generate file `solutions/0001-two-sum.cpp`:
```cpp
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // TODO: Implement solution
        return {};
    }
};
// @lc code=end

#include "leetcode/runner.h"
#include <doctest/doctest.h>

TEST_CASE("0001") {
    auto f = Runner(1, &Solution::twoSum);
    REQUIRE_EQ(f({2, 7, 11, 15}, 9), std::vector{0, 1});
    REQUIRE_EQ(f({3, 2, 4}, 6), std::vector{1, 2});
    REQUIRE_EQ(f({3, 3}, 6), std::vector{0, 1});
}
```

## Important Notes

- Problem ID must be zero-padded to 4 digits in filename and TEST_CASE string
- File naming convention: `<4-digit-id>-<slug>.cpp`
- Always include `// @lc code=start` and `// @lc code=end` markers (only code between these markers should be submitted to LeetCode)
- Include `leetcode/runner.h` before TEST_CASE when using Runner
- Keep the solution skeleton minimal but compilable
- Run `python3 scripts/gen.py` after creating the file to update CMakeLists.txt
