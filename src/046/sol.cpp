#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> retVec;
        retVec.clear();

        if (nums.size() == 1) {
            vector<int> tmp;
            tmp.clear();
            tmp.push_back(nums[0]);
            retVec.push_back(tmp);
            return retVec;
        }

        for (int i = 0; i < nums.size(); ++i) {
            int tmp = nums[i];
            nums.erase(nums.begin() + i);

            vector<vector<int>> tmpCombination = permute(nums);
            for (int j = 0; j < tmpCombination.size(); ++j) {
                tmpCombination[j].insert(tmpCombination[j].begin(), tmp);
                retVec.push_back(tmpCombination[j]);
            }

            nums.insert(nums.begin() + i, tmp);
        }

        return retVec;
    }
};