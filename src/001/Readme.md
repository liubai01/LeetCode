## LeetCode 001: Two sum

### Problem

[Problem link](https://leetcode.com/problems/two-sum/)

### Solution description

The trickiest part is that the problem guarantees that there is only one solution for this problem. 

The solution is: traverse the list and add each integer into a hash map at the same time.

- Check if current number `target` - `a` in hash map. 
  - If it is, then it means `a` plus some number we have visited equals to `target`. 
  - If it is not, add current number into hash map. 
    - It must be visited in the future if some integer plus it equals to `target`.

### File structure

 - `sol.cpp`: baseline solution
 - `sol_hash.cpp`: speed-up solution with hash map
 - `testcases\..`: testcases

### Run testcases

```powershell
# On Windos(GCC) 5.3.0)
g++ .\testcases\test01.cpp -o test01.exe -std=c++0x
```

Modify `../sol_hash.cpp` to `../sol.cpp`  in `test01.cpp` to apply testcases on different solutions.

### Performance

| Solution             | Link         | Runtime | Memory Usage |
| ------------------------ | ------- | ------------ | ------------ |
| Brute-force(nested loop) | [sol.cpp](sol.cpp) | 1108 ms | 7 MB         |
| Hash map based           | [sol_hash.cpp](sol_hash.cpp) | 24ms    | 8.3MB        |

