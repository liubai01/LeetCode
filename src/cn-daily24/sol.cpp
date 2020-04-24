#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int divdeAndConquer(vector<int>& nums, int& cnter, int left, int right) {
        int mid = (left + right) / 2;
        int left_p = left;
        int right_p = mid + 1;

        if (right - left + 1 == 1) {
            return 0;
        }
        if (right - left + 1 == 2) {
            if (nums[left] > nums[right]) {
                int t = nums[left];
                nums[left] = nums[right];
                nums[right] = t;
                cnter += 1;
            }
            return 0;
        }
        vector<int> tmp;
        int in_tmp_right = 0;
        tmp.clear();

        divdeAndConquer(nums, cnter, left, mid);
        divdeAndConquer(nums, cnter, mid + 1, right);
        while (left_p <= mid && right_p <= right) {
            if(nums[left_p] <= nums[right_p]) {
                tmp.push_back(nums[left_p]);
                ++left_p;
                cnter += right_p - mid - 1;
            } else {
                tmp.push_back(nums[right_p]);
                ++right_p;
            }
        }
        while (left_p <= mid) {
            tmp.push_back(nums[left_p]);
            ++left_p;
            cnter +=  right_p - mid - 1;
        }
        while (right_p <= right) {
            tmp.push_back(nums[right_p]);
            ++right_p;
        }
        for(int i = left; i <= right; ++i) {
            nums[i] = tmp[i - left];
        }

        return 0;
    }

    int reversePairs(vector<int>& nums) {
        int cnter = 0;
        if (nums.size() == 0 ) return 0;
        divdeAndConquer(nums, cnter, 0, nums.size() - 1);

        return cnter;
    }
};