## LeetCode 023: Merge k Sorted Lists

### Problem

[Problem link](https://leetcode-cn.com/problems/merge-k-sorted-lists/)

### Solution description

That is a very intuitive problem: we first add first elements of lists into a heap. Then, pop elements from the top and add it into output queue, and add the next element of the popped element from its original list. The motivation behind this algorithm is that this policy help us maintain minimal unvisited elements with respect to each list in the heap. And when we popped from the heap, we get the global minimal among the lists.

The time complexity should be `nlog(k)`. The time complexity of pushing an element is `log(k).`

### File structure

 - `sol.cpp`: baseline solution

### Performance

| Solution             | Link         | Runtime | Memory Usage |
| ------------------------ | ------- | ------------ | ------------ |
| Heap | [sol.cpp](sol.cpp) | 48ms | 11.2MB |

