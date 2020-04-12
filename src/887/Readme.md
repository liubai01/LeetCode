## LeetCode 887: Super Egg Drop

### Problem

[Problem link](https://leetcode-cn.com/problems/super-egg-drop/)

### Solution description

This problem is quite a challenging problem. It sources from a google interview question.

#### Baseline: Dynamic programming

The sub-optimal structure is(dp(n, k) denotes optimal solution):

$$
Dp(n, k) = 1 + \min_i \max\{ Dp(i - 1, k - 1), Dp(n - i, k)\}
$$

While the boundary case is trivial:

$$
Dp(n, 1) = n
$$

$$
Dp(1, k) = 1
$$

$$
Dp(0, k) = 0
$$

```c++
for (int drop_lvl = 1;  drop_lvl <= n; ++drop_lvl){
    int broken_times = 1 + dpSolve(k - 1, drop_lvl - 1, K, N);
    int unbroken_times = 1 + dpSolve(k, n - drop_lvl, K, N);
    int worse_case = max(broken_times, unbroken_times);
    if (worse_case < now_min) {
        now_min = worse_case;
    }
}
```

The previous dynamic programming can roughly pass 10~20 testcases.

#### Advanced 1: Optimal halting

However, the brute-force local search the minimum is inefficient. 

Note the fact that when `k` fixed, `Dp(n,k)` increases monotonously as `n` grows, which means `Dp(i - 1, k - 1)` grows as `i` grows while  `Dp(n - i, k)` decreases.

 The global optimal with respect to one `Dp(n,k)=1 + min...`process is the cross point of  `Dp(i - 1, k - 1)`,  `Dp(n - i, k)` since final result takes their maximum. Halt if `Dp(i - 1, k - 1)` >  `Dp(n - i, k)` can skip unnecessary computational cost. 

```cpp
for (int drop_lvl = 1;  drop_lvl <= n; ++drop_lvl){
    int broken_times = 1 + dpSolve(k - 1, drop_lvl - 1, K, N);
    int unbroken_times = 1 + dpSolve(k, n - drop_lvl, K, N);
    int worse_case = max(broken_times, unbroken_times);

    if (worse_case < now_min) {
        now_min = worse_case;
    }
    // optimal halting
    if (broken_times > unbroken_times) break;
}
```

The previous optimal halting strategy can help you pass 1/3 testcases.

#### Advanced 2: Binary search

Binary search is intuitive based on optimal halting solution.  Talk is cheap. Here show you the code:

```cpp
int dpSolve(int k, int n, int K, int N) {
    int now_min = 9999999;
    int low_drop = 1;
    int high_drop = n;
    int thre = 10;

    // memorized
    if (dp[k][n] != -1) return dp[k][n];
	// binary search
    while (high_drop - low_drop > thre) {
        int drop_lvl = (low_drop + high_drop) / 2;
        int broken_times = 1 + dpSolve(k - 1, drop_lvl - 1, K, N);
        int unbroken_times = 1 + dpSolve(k, n - drop_lvl, K, N);
        int worse_case = max(broken_times, unbroken_times);

        if (worse_case < now_min) {
            now_min = worse_case;
        }

        if (broken_times > unbroken_times) {
            high_drop = drop_lvl;
        } else {
            low_drop = drop_lvl;
        }
    }
    // optimal halting
    for (int drop_lvl = max(1, low_drop - 1);  drop_lvl <= min(high_drop + 1, n); ++drop_lvl){
        int broken_times = 1 + dpSolve(k - 1, drop_lvl - 1, K, N);
        int unbroken_times = 1 + dpSolve(k, n - drop_lvl, K, N);
        int worse_case = max(broken_times, unbroken_times);
        if (worse_case < now_min) {
            now_min = worse_case;
        }

        if (broken_times > unbroken_times) {
            dp[k][n] = now_min;
            return dp[k][n];
        }

    }
    dp[k][n] = now_min;
    return dp[k][n];
}
```

### File structure

 - `sol.cpp`: final AC version
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
| DP + binary search | [sol.cpp](sol.cpp) | 100 ms | 9.7 MB |
|          |      |         |              |

