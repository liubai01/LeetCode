## LeetCode cn-面试题13. 机器人的运动范围

### Problem

[Problem link](https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/)

### Solution description

就是一道简单的BFS。回顾一下C++ Queue的API

### File structure

 - `sol.cpp`: solution
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
| BFS | [sol.cpp](sol.cpp) | 4ms(81.25%) | 6.2MB(100%) |
|          |      |         |              |

