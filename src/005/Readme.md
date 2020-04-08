## LeetCode 005: Longest Palindromic Substring

### Problem

[Problem link](https://leetcode.com/problems/longest-palindromic-substring/)

### Solution description

Some utils I met while solving this problem:

- Get sub-string: `str.substr(<start_idx>, <str_len>)`

My `dp status function` is a 2d Boolean array, where:

- `dp[i][j]` indicates whether string starts at index j with length i is palindromic
- Omit boundary case: `dp[i][j]` = `dp[i - 2][j]` && `(s[j] == s[j + i])`

Update `max_len` when any `dp[i][j]` is true as i grows. That is a O(n^2) solution.

### File structure

 - `sol.cpp`: baseline solution
 - `sol_dp.cpp`: the dynamic programming solution
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
| Brute-force | [sol.cpp](sol.cpp) | 47/103 tests pass, time limit exceeds | N/A |
| Dynamic programming | [sol_dp.cpp](sol_dp.cpp) | 164ms(30.22%) | 7.7MB(100%) |

