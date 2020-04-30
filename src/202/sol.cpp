#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> hasVistied;
        hasVistied.clear();

        while (true)
        {
            int tmp = n;
            int next = 0;
            while (tmp > 0) {
                next += (tmp % 10) * (tmp % 10);
                tmp = tmp / 10;
            }
            if (next == 1) {
                return true;
            }
            if (hasVistied.find(next) != hasVistied.end()) {
                return false;
            }
            n = next;
            hasVistied.insert(n);
            
        }

        return true;
    }
};