#include <iostream>
#include <string>
#include <vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> ret_v;

        for (int i = 0; i < nums.size(); ++i) {
            int tgt_num = target - nums[i];
            if (hash.find(tgt_num) != hash.end()) {
                ret_v.push_back(hash[tgt_num]);
                ret_v.push_back(i);
                break;
            }
            hash[nums[i]] = i;
        }
        return ret_v;
    }
    
};