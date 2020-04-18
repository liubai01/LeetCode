#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxVol = 0;

        for (int i = 0; i < height.size(); ++i) {
            for (int j = height.size() - 1; j >= 0; --j) {
	            int maxPosVol = (j - i) * height[i];
	            if (maxPosVol <= maxVol) break;
                int nowVol = (j - i) * min (height[i], height[j]);
                if (nowVol > maxVol) {
                    maxVol = nowVol;
                }
            }
        }

        return maxVol;
    }
};