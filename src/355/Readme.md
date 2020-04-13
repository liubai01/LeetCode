## LeetCode 335: [Design Twitter](https://leetcode-cn.com/problems/design-twitter/)

### Problem

[Problem link](https://leetcode-cn.com/problems/design-twitter/)

### Solution description

That is a application-based task. Recently, my problem-solving ability towards cpp seems not very well.

You are supposed to note an exception: a user cannot follow himself or herself: `followerId` != `followeeId`.

And the algorithm should focus on how to rapidly query recent tweets for one user's followees:

- Save latest tweet for a user as a stack LIFO, to make sure that we could access latest tweet.
- Employ a priority queue to compare which tweet is latest among different followees.

Note to truncate the redundancy of your program.

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
| Naive | [sol.cpp](sol.cpp) | 92 ms | 21.9MB |
|          |      |         |              |

