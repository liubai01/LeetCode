#include <iostream>
#include <string>

using namespace std;

bool compare(vector<int>& a, vector<int>& b)
{
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> retIntervals;
        vector<int> prevI;
        bool first = true;

        std::sort(intervals.begin(), intervals.end(), compare);
        retIntervals.clear();

        for (auto ii = intervals.begin(); ii != intervals.end(); ++ii) {
            vector<int> i = *ii;
            if (first) {
                prevI = i;
                first = false;
                continue;
            } else {
                // should merge
                if (i[0] <= prevI[1]) {
                    if (i[1] <= prevI[1]) continue;
                    else {
                        prevI[1] = i[1];
                    }
                } else {
                    retIntervals.push_back(prevI);
                    prevI = i;
                }
            }   
        }
        if (!first) {
            retIntervals.push_back(prevI);
        }
        return retIntervals;
    }
};