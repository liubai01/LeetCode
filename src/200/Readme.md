## LeetCode 200: Number of Islands

### Problem

[Problem link](https://leetcode-cn.com/problems/number-of-islands/)

### Solution description

It is a naïve BFS solution. BFS all neighboring lands and label them as `visited` when update counter for any one land. Update until all blocks in grid are labelled as visited.

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
| BFS | [sol.cpp](sol.cpp) | 20ms(32.48%) | 9.7MB |

