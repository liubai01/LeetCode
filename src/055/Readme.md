## LeetCode 55: Jump Game

### Problem

[Problem link](https://leetcode-cn.com/problems/jump-game/)

### Solution description

A standard `dp` problem, whether current possible is accessible is decided by whether one of previous accessible-to-this-pos regions is reachable. Memorize it and solve it recursively.

**Update**: OMG, this is an extremely easy greedy problem, I mess it up by dynamic programming.

**Heuristics:**

```cpp
bool canJumpDp(vector<bool>& dp, vector<bool>& visited, vector<int>& nums, int j) {
        if (visited[j]) return dp[j];
        bool jdpVal = false;
        for (int k = j - 1; k >= 0; --k) {
            if (visited[k]) {
                jdpVal = jdpVal || (dp[k] && (nums[k] + k >= j));
            } else {
                jdpVal = jdpVal || canJumpDp(dp, visited, nums, k) && (nums[k] + k >= j);
            }
            if (jdpVal) break;
        }
        visited[j] = true;
        dp[j] = jdpVal;

        return jdpVal;
    }
}
```

Note the loop `for (int k = j - 1; k >= 0; --k)` goes from the nearest position for searching and halts if reachable by one region: `if (jdpVal) break;`. This design is to optimize the performance of program by **locality assumption**. The loop goes from other sides will fail last few testcases.

The memory usage may not be economical and should be optimized.

### File structure

 - `sol.cpp`: dynamic programming
 - `testcases\..`: testcases

### Run testcases

No testcase for this problem.

### Performance

| Solution             | Link         | Runtime | Memory Usage |
| ------------------------ | ------- | ------------ | ------------ |
| dynamic programming | [sol.cpp](sol.cpp) | 16ms(36.98%) | 20MB(8.7%) |
|          |      |         |              |

