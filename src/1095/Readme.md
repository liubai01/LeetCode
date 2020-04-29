## LeetCode 1095: Find in Mountain Array

### Problem

[Problem link](https://leetcode-cn.com/problems/find-in-mountain-array/)

### Solution description

Honestly, I snoop the solution because my previous implementation of binary search is tedious.

The general idea of this algorithm is to firstly search a peak by binary search. Then the problem is split to two binary search (the upside part and the downside part). And the problem solved. I will list binary search below for rapid query next time:

```cpp
int binarySearch(int l, int r, int target, MountainArray &mountainArr, bool up) {
        while (l <= r) {
            
            int mid = (l + r) / 2;
            int now = mountainArr.get(mid);

            if (now == target) {
                return mid;
            } else {
                if (up) {
                    if (now < target) {
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                } else {
                    if (now < target) {
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
            }
        }
        return -1;
    }
```

### File structure

 - `sol.cpp`: baseline solution

### Performance

| Solution             | Link         | Runtime | Memory Usage |
| ------------------------ | ------- | ------------ | ------------ |
| binary search x3 | [sol.cpp](sol.cpp) | 4ms(96.67%) | 7.1MB(100%) |

