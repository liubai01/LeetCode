## LeetCode 053: Maximum Subarray

### Problem

[Problem link](https://leetcode-cn.com/problems/maximum-subarray/)

### Solution description

The core idea is: if the current subarray adds below zero, drop current subarray and start a new one after that. Followed by this rule, we could find maximum subarray ending with current element that we are visiting. Traverse the subarray and we would get the optimal solution.

### File structure

 - `sol.cpp`: baseline solution

### Performance

| Solution             | Link         | Runtime | Memory Usage |
| ------------------------ | ------- | ------------ | ------------ |
| slide window | [sol.cpp](sol.cpp) | 8ms(74.51%) | 7MB(100.00%) |

