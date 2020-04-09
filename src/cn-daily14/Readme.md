## LeetCode cn-面试题14: 括号生成

### Problem

[Problem link](https://leetcode-cn.com/problems/generate-parentheses/)

### Solution description

应该能用DP+模拟解，但感觉DFS比较暴力，代码比较简单。所以我比较喜欢：）。

回顾一下C++ string的API吧，好久没用了，果真还是那股难用的味道。

### File structure

 - `sol.cpp`: baseline solution
 - `testcases\..`: testcases

### Run testcases

```powershell
# On Windos(GCC) 5.3.0)
g++ .\testcases\test01.cpp -o test01.exe -std=c++0x
```

Modify `../sol.cpp`  in `test01.cpp` to apply testcases on different solutions.

### Performance

| Solution             | Link         | Runtime | Memory Usage |
| ------------------------ | ------- | ------------ | ------------ |
| DFS | [sol.cpp](sol.cpp) | 16ms | 8.6MB |
|          |      |         |              |

