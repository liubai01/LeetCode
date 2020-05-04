class Solution {
public:
    int jump(vector<int>& nums) {
        int cnter = 0;
        int now = 0;
        while (now < nums.size() - 1) {
            int tmp = now + nums[now];
            cnter += 1;

            if (tmp >= nums.size() - 1) {
                break;
            } else {
                int nowMax = -1;
                for (int i = now + 1; i <= min(tmp, (int) nums.size() - 1); ++i) {
                    if (nums[i] + i > nowMax) {
                        nowMax = nums[i] + i;
                        now = i;
                    }
                }
            }
        }
        return cnter;
    }
    
};