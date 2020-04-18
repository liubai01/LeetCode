## LeetCode 042: Trapping Rain Water

### Problem

[Problem link](https://leetcode-cn.com/problems/trapping-rain-water/)

### Solution description

My inefficient solution has completed. However, the official implementation if more efficient. Its idea is: `fill water height of a block = min(max height left to this block, max height right to this block) - the height of this block`. Those two lists of variable could be memorized so algorithm goes to O(n). Awesome!

### File structure

 - `sol_stackmy.cpp`: baseline solution
 - `testcases\..`: testcases

### Run testcases

Note testcase for this task.

### Performance

| Solution             | Link         | Runtime | Memory Usage |
| ------------------------ | ------- | ------------ | ------------ |
| stack(inefficient) | [sol_stackmy.cpp](sol_stackmy.cpp) | 100ms | 15.4MB |
| dp(efficient) | [sol_dp.cpp](sol_dp.cpp) | 8 ms | 7.1MB |

