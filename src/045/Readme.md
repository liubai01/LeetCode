## LeetCode 045: Jump Game II

### Problem

[Problem link](https://leetcode-cn.com/problems/jump-game-ii/)

### Solution description

The problem is  very similar to  [gas station](https://www.csee.umbc.edu/~hillol/CLASSES/CMSC441Spring2013/NOTES/lecture8.pdf) problem. Greedy method could be applied to this problem with time complexity `O(n)`, which follows idea that `reach the stair that could reach the furtherest stair at each leap`.

The worst case for DP of this problem is `O(n^2)` and would fail last two testcases.

### File structure

 - `sol_greed.cpp`: greedy solution
 - `sol_dp.cpp`: dynamic programming solution(out of time limitation)

### Performance

| Solution             | Link         | Runtime | Memory Usage |
| ------------------------ | ------- | ------------ | ------------ |
| dynamic programming | [sol_dp.cpp](sol_dp.cpp) | 90/92 cases |              |
| greedy | [sol_greed.cpp](sol_greed.cpp) | 12ms(65.51%) | 7.8MB |

