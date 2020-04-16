## LeetCode 56: Merge Intervals

### Problem

[Problem link](https://leetcode-cn.com/problems/merge-intervals/)

### Solution description

This is a very simple question if you are familiar with built in sorting API:

```cpp
std::sort(intervals.begin(), intervals.end(), compare);
```

Sort the intervals by arrival time of intervals. Traverse the list to merge. For each element, check whether there is an overlap for the previous interval.

### File structure

 - `sol.cpp`: solution

### Run testcases

No testcase for this problem.

### Performance

| Solution             | Link         | Runtime | Memory Usage |
| ------------------------ | ------- | ------------ | ------------ |
| sorting | [sol.cpp](sol.cpp) | 40 ms | 11 MB |
|          |      |         |              |

