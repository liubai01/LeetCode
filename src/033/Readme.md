## LeetCode 33: Search in Rotated Sorted Array

### Problem

[Problem link](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)

### Solution description

#### My implementation: binary search + binary search

My design of algorithm in this task follows reduction: first find out the rotated breakpoint(a.k.a minima in some position), then convert this problem into a naïve binary search problem.

##### Step1: Find out the breakpoint

It also follows a binary search of `O(log n)` time complexity. 

- When element at middle is larger than the left and right one, the breakpoint is at right-half.
- When element at middle is smaller than the left and right one, the breakpoint is at left-half.
- Otherwise, the element is between the left and right one, which means the left one is minimal.

##### Step2: Find out the target

That follows a standard binary search process in a sorted array. Omit here.

#### Official implementation: one-shot binary search

Quote the implementation from the [leetcode official](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/sou-suo-xuan-zhuan-pai-xu-shu-zu-by-leetcode-solut/) here:

```cpp
// https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/sou-suo-xuan-zhuan-pai-xu-shu-zu-by-leetcode-solut/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n) return -1;
        if (n == 1) return nums[0] == target ? 0 : -1;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
```

The official implementation omits the process of finding out the breakpoint, it points out an interesting observation: either the left-half or right-half is sorted and could be decided by comparing the relationship among `left`, `right` and `mid`. Therefore, deciding whether target is included at left-half or right-half is efficiently solved, which is more elegant than my method.

### File structure

 - `sol.cpp`: binary search + binary search

### Performance

| Solution             | Link         | Runtime | Memory Usage |
| ------------------------ | ------- | ------------ | ------------ |
| Binary search + binary search | [sol.cpp](sol.cpp) | 0ms | 6.5MB |

