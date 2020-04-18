## LeetCode 11: Container With Most Water

### Problem

[Problem link](https://leetcode-cn.com/problems/container-with-most-water/)

### Solution description

#### Solution 1: Brute force

Brute force solution with some tricks can pass all tests with low performance. It goes through all possible combination of `(i, j)` and finds one with max volume. The naïve brute-force method could pass 47/50 testcases.

One trick is to skip if following solution is impossible:

### File structure

 - `sol.cpp`: baseline solution
 - `testcases\..`: testcases

### Run testcases

No testcase for this problem.

### Performance

| Solution             | Link         | Runtime | Memory Usage |
| ------------------------ | ------- | ------------ | ------------ |
| brute force | [sol_bf.cpp](sol_bf.cpp) | 564 ms | 7.5 MB |
| greedy | [sol_greed.cpp](sol_greed.cpp) | 16ms | 7.6 MB |

