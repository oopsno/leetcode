# AGENTS.md

LeetCode solutions in C++23.

## Build & Test

```bash
cmake --preset default
cmake --build build
ctest --test-dir build
```

Ninja is the generator. `build/` is the only build dir; `build/compile_commands.json` lands there for clangd.

## Adding a Solution

1. Create `solutions/NNNN-problem-name.cpp` (4-digit zero-padded number).
2. Run `python3 scripts/gen.py` to regenerate `solutions/CMakeLists.txt`. Only files matching `^\d{4}-` are picked up.
3. Rebuild.

Do **not** edit `solutions/CMakeLists.txt` manually — it is generated.

## Renaming Solutions

To rename existing solution files to match the naming convention:

```bash
python3 scripts/rename_solutions.py
```

This script:
- Finds files not matching `NNNN-slug.cpp` pattern
- Fetches problem slugs from leetcode-local-cli
- Renames files to `NNNN-slug.cpp` format

## Solution File Pattern

Each `.cpp` file is self-contained: includes, `Solution` class, and doctest `TEST_CASE` at the bottom. Tests use the project helpers from `include/` (e.g., `makeListFrom`, `compareListNode`, `stringToTreeNode`).

Two ListNode definitions exist: `include/list-node.h` (standalone, with helpers) and `include/leetcode.hpp` (namespace `leetcode`). Prefer `include/list-node.h` for new solutions — it provides `makeListFrom` and `compareListNode`.

## Style

Google-based clang-format (`.clangformat`). 80-col limit, 2-space indent, `Attach` braces.

Each solution contains 3 parts:

1. docstring 
  1. domain name of leetcode, problem id, language, 
  2. human-readable problem name
2. solution code surrounded by special comment `// @lc code=start` and `// @lc code=end`; only submit these codes to LeetCode.
3. unittest code

```cpp
/*
 * @lc app=leetcode.cn id=9876 lang=cpp
 *
 * [9876] example problem
 */

namespace {
// @lc code=start
#include <vector>
class Solution {
    int solve(int x) { return x + 1; }
};
// @lc code=end
} // namespace <anonymous>

#include "leetcode/runner.h"
#include <doctest/doctest.h>

TEST_CASE("9876") {
    auto f = Runner(9876, &Solution::solve);
    REQUIRE_EQ(f(4), 5);
}
```

For tree problems, include `leetcode/tree-node.h` before `@lc code=start` to define `TreeNode`, and use `stringToTreeNode` for test cases:

```cpp
/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */

#include "leetcode/tree-node.h"

// @lc code=start
#include <algorithm>

class Solution {
public:
  int maxDepth(TreeNode *root) {
    return root == nullptr
               ? 0
               : std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};
// @lc code=end

#include <doctest/doctest.h>

TEST_CASE("0104") {
  auto empty = stringToTreeNode("[]");
  REQUIRE_EQ(Solution().maxDepth(empty), 0);
  auto tree = stringToTreeNode("[3,9,20,null,null,15,7]");
  REQUIRE_EQ(Solution().maxDepth(tree), 3);
}
```