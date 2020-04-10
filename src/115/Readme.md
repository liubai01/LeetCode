## LeetCode 115:  Reverse Words in a String

### Problem

[Problem link(cn-leetcode)](https://leetcode-cn.com/problems/reverse-words-in-a-string/)

The problem at China station should be consistent with the International station.

### Solution description

That problem is to train you with **boundary cases**. Design a FSM properly is extremely important.

It sounds like a simple problem. And in fact it is, however, you should focus on:

- What if the input is a empty string(`""`)?
- What if the input is a single letter(`"a"`)?
- What if the input is a single blank(`" "`)?
- How you deal with the last letter?

How to solve this problem is not the point. What matters is how you could efficiently design a **FSM(Finite state machine)** with the least computational cost and the developmental time cost.

### File structure

 - `sol.cpp`: baseline solution
 - `testcases\..`: testcases

### Run testcases

```powershell
# On Windos(GCC) 5.3.0)
g++ .\testcases\test01.cpp -o test01.exe -std=c++0x
```

### Performance

| Solution             | Link         | Runtime | Memory Usage |
| ------------------------ | ------- | ------------ | ------------ |
| Simulation | [sol.cpp](sol.cpp) | 8ms | 8.8MB |

