#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
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
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size());
        vector<bool> visited(nums.size());

        dp.clear();
        visited.clear();

        visited[0] = true;
        dp[0] = true;

        return canJumpDp(dp, visited, nums, nums.size() - 1);
    }
};