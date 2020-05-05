## LeetCode 098: Validate Binary Search Tree

### Problem

[Problem link](https://leetcode-cn.com/problems/validate-binary-search-tree/)

### Solution description

Since BST is defined recursively, then we could validate the binary tree recursively:

> The left subtree of a node contains only nodes with keys less than the node's key.
> The right subtree of a node contains only nodes with keys greater than the node's key.
> Both the left and right subtrees must also be binary search trees.

### File structure

 - `sol.cpp`: baseline solution

### Performance

| Solution             | Link         | Runtime | Memory Usage |
| ------------------------ | ------- | ------------ | ------------ |
| Naïve method | [sol.cpp](sol.cpp) | 16ms(75.10%) | 18.4MB |

