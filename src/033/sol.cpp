#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int bp; // breakpt
        // find break point
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right) / 2;
        int stop_threshold = 5;

        // boundary case
        if (nums.size() == 0) return -1;

        while (right - left > stop_threshold) {
            if (nums[mid] > nums[left] && nums[mid] > nums[right]) {
                left = mid;
                mid = (left + right) / 2;
                continue;
            }
            if (nums[mid] < nums[left] && nums[mid] < nums[right]) {
                right = mid;
                mid = (left + right) / 2;
                continue;
            }
            break;
        }
        if (right - left > stop_threshold) {
            bp = 0;
        } else {
        int minEle = 0x7FFFFFFF;
            for (int i = left; i <= right; ++i) {
                if (nums[i] < minEle) {
                    minEle = nums[i];
                    bp = i;
                }
            }
        }


        // find the target element
        // sorted -> not sorted: (idx + bp) & nums.size()
        left = 0; // the idx in sorted coord.
        right = nums.size() - 1; // the idx in sorted corrd.
        mid = (left + right) / 2;
        while (right - left > stop_threshold) {
            if (target > nums[(mid + bp) % nums.size()]) {
                left = mid;
                mid = (left + right) / 2;
            } else {
                right = mid;
                mid = (left + right) / 2;
            }
        }
        for (int i = left; i <= right; ++i) {
            if (nums[(i + bp) % nums.size()] == target) {
                return (i + bp) % nums.size();
            }
        }

        return -1;
    }
};