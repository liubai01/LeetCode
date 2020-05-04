class Solution {
public:
    int jumpDp(vector<int>&nums, vector<int>& minimal, int n) {
        if (minimal[n] != -1) return minimal[n];
        int opt = -1;
        for(int k = n - 1; k >= searchStop[n]; --k) {
            if (k + nums[k] >= n) {
                if (minimal[k] == -1) jumpDp(nums, minimal, searchStop, k);
                if (opt == -1) {
                    opt = minimal[k] + 1;
                } else {
                    opt = min(opt, minimal[k] + 1);
                }
            }
        }
        minimal[n] = opt;

        return opt;
    }

    int jump(vector<int>& nums) {
        vector<int> minimal(nums.size());

        minimal[0] = 0;
        for (int i = 1; i < nums.size(); ++i) {
            minimal[i] = -1;
        }


        return jumpDp(nums, minimal, nums.size() - 1);
    }
};