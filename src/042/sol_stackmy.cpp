#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int totVol = 0;
        bool startFirstDrop = false;
        stack<vector<int>> pilrs;
        vector<int> toPush;

        for(int i = 0; i < height.size(); ++i) {
            int nowHeight = height[i];
            int fillWidth = 0;
            if (!pilrs.empty() && nowHeight < pilrs.top()[0]) startFirstDrop = true;
            // if rise (left->right) detected
            if (!pilrs.empty() && nowHeight > pilrs.top()[0] && startFirstDrop) {
                bool fillFirstRise = false; // right->left
                cout << "Start filled: " << i << " " << endl;
                // water fill
                stack<vector<int>> toBeFilled;
                int fillHeight;
                while (!pilrs.empty() && pilrs.top()[0] < nowHeight) {
                    if (!fillFirstRise && !toBeFilled.empty() && pilrs.top()[0] > toBeFilled.top()[0]) fillFirstRise = true;
                    // avoid boundary cases
                    if (fillFirstRise && pilrs.top()[0] < toBeFilled.top()[0]) {
                        pilrs.push(toBeFilled.top());
                        toBeFilled.pop();
                        break;
                    }
                    cout << "To be filled: pushed " << pilrs.top()[0] << " " << pilrs.top()[1] << endl;
                    toBeFilled.push(pilrs.top());
                    pilrs.pop();
                }
                // decide fill height
                if(pilrs.empty()) {
                    fillHeight = toBeFilled.top()[0];
                } else {
                    fillHeight = min(pilrs.top()[0], nowHeight);
                }
                cout << "Fill height: " << fillHeight << " " << endl;
                // start fill
                while (!toBeFilled.empty()) {
                    cout << "To be filed top: " << toBeFilled.top()[0] << endl;
                    if(toBeFilled.top()[0] <= fillHeight){
                        totVol += (fillHeight - toBeFilled.top()[0]) * toBeFilled.top()[1];
                        cout << "Fill Vol: " << (fillHeight - toBeFilled.top()[0]) * toBeFilled.top()[1] << endl;
                        fillWidth += toBeFilled.top()[1];
                        toBeFilled.pop();
                    } else {
                        break;
                    }
                }
                // cout << fillHeight << " " << fillWidth << endl;
                if (fillWidth > 0) {
                    toPush.clear();
                    toPush.push_back(fillHeight);
                    toPush.push_back(fillWidth);
                    pilrs.push(toPush);
                }
                // clearn toBeFilled
                while (!toBeFilled.empty()) {
                    pilrs.push(toBeFilled.top());
                    toBeFilled.pop();
                }
            }
            // addNewArrival pillar
            toPush.clear();
            toPush.push_back(nowHeight);
            toPush.push_back(1);
            pilrs.push(toPush);
        }
        return totVol;
    }
};