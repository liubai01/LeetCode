class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int nowMax = 0;
        int retMax = 0x80000000;
        for (int i = 0; i < nums.size(); ++i) {
            nowMax = max(0, nowMax) + nums[i];
            retMax = max(retMax, nowMax);
        }
        return retMax;
    }
};