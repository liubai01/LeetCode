## LeetCode 3: Longest Substring Without Repeating Characters

### Problem

[Problem link](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)

### Solution description

This is a very simple problem. Relying on slide windows, while moving `right-pointer` to right one character at each step, move `left-pointer` to right if there is still repeating character in substring(implemented by `<unordered_set>` in cpp by hashing).

#### Engineering issues

I am faced with the inconsistent computation between `unsigned`  and `signed` variables in this problem. Here is the code segment:

```cpp
maxLen = max(maxLen, (int) s.length() - startIdx);
```

[Here](sol.cpp), note that `s.length()` is the unsigned integer, while `startIdx` defined before is the signed(by default) integer. Directly applying difference between them may treat `startIdx` as unsigned integer, regarding its first signed bit as the most significant bit, which leads to unexpected computation. That case will cause disaster at online project. Be really careful here.

### File structure

 - `sol.cpp`: baseline solution

### Performance

| Solution             | Link         | Runtime | Memory Usage |
| ------------------------ | ------- | ------------ | ------------ |
| sliding window | [sol.cpp](sol.cpp) | 4 ms (98.84%) | 6.8 MB (100.00%) |

