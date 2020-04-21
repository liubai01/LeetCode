#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        if (nums.size() == 0) return 0;
        int totCnter = 0;
        int oddStartIdx = -1;
        int nowOddNum = 0;
        int i;

        // first interval
        for (i = 0; i < nums.size(); ++i) {
            // is Odd
            if(nums[i] % 2 == 1) {
                if (oddStartIdx == -1) {
                    oddStartIdx = i;
                }
                nowOddNum += 1;
                if (nowOddNum == k) {
                    break;
                }
            }
            if (i == nums.size() - 1) return 0;
        }
        int left_margin_start = 0;
        while (true) {
            int right_margin_end;
            // search right margin
            for (right_margin_end = i; right_margin_end + 1 < nums.size(); ++right_margin_end) {
                if (nums[right_margin_end + 1] % 2 == 1) break;
            }
            // update counter
            totCnter += (oddStartIdx - left_margin_start + 1) * (right_margin_end - i + 1);
            if (right_margin_end + 1 == nums.size()) return totCnter;
            i = right_margin_end + 1;
            // update left margin
            left_margin_start = oddStartIdx + 1;
            // update oddStartIdx until found odd
            for (oddStartIdx = left_margin_start; oddStartIdx <nums.size(); ++oddStartIdx) {
                if (nums[oddStartIdx] % 2 == 1) break;
            }

        }
        
        return totCnter;
    }
};