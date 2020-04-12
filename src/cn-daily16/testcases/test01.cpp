// // This script is compiled under windows
// g++ test01.cpp -o test01.exe -std=c++0x

#include <iostream>
#include <string>
#include <vector>
#include<cmath>

#include "../sol.cpp"

using namespace std;

void outputPt(vector<double>& pt) {
    if (pt.empty()) {
        cout << "No intersaction" << endl;
    } else {
        cout << "(" << pt[0] << ", " << pt[1] << ")" << endl;
    }
}

void testcase01(Solution& sol) {
    cout << "=====Testase 1.1.2 (1)=====" << endl;

    vector<int> start1 = {0, 0};
    vector<int> start2 = {0, 1};
    vector<int> end1 = {0, 0};
    vector<int> end2 = {-1, 0};

    vector<double> retPt = sol.intersection(start1, start2, end1, end2);
    outputPt(retPt);
}

void testcase02(Solution& sol) {
    cout << "=====Testase 1.1.2 (2)=====" << endl;

    vector<int> start1 = {0, 0};
    vector<int> start2 = {0, 1};
    vector<int> end1 = {-1, 0};
    vector<int> end2 = {-2, 0};

    vector<double> retPt = sol.intersection(start1, start2, end1, end2);
    outputPt(retPt);
}

void testcase03(Solution& sol) {
    cout << "=====Testase 1.1.1=====" << endl;

    vector<int> start1 = {0, 0};
    vector<int> start2 = {0, 1};
    vector<int> end1 = {0, 4};
    vector<int> end2 = {-4, 4};

    vector<double> retPt = sol.intersection(start1, start2, end1, end2);
    outputPt(retPt);
}

void testcase04(Solution& sol) {
    cout << "=====Testase 1.3.1=====" << endl;

    vector<int> start1 = {0, 0};
    vector<int> start2 = {0, 1};
    vector<int> end1 = {3, 2};
    vector<int> end2 = {3, 3};

    vector<double> retPt = sol.intersection(start1, start2, end1, end2);
    outputPt(retPt);
}

void testcase05(Solution& sol) {
    cout << "=====Testase 1.3.2 inetrsaction =====" << endl;

    vector<int> start1 = {0, 0};
    vector<int> start2 = {0, 2};
    vector<int> end1 = {0, 1};
    vector<int> end2 = {0, 3};

    vector<double> retPt = sol.intersection(start1, start2, end1, end2);
    outputPt(retPt);
}

void testcase06(Solution& sol) {
    cout << "=====Testase 1.3.2 no inetrsaction =====" << endl;

    vector<int> start1 = {0, 0};
    vector<int> start2 = {0, 3};
    vector<int> end1 = {0, 2};
    vector<int> end2 = {0, 4};

    vector<double> retPt = sol.intersection(start1, start2, end1, end2);
    outputPt(retPt);
}

void testcase07(Solution& sol) {
    cout << "=====Testase 1.2.1 inetrsaction =====" << endl;

    vector<int> start1 = {0, 0};
    vector<int> end1 = {0, 3};
    vector<int> start2 = {-1, -1};
    vector<int> end2 = {1, 3};

    vector<double> retPt = sol.intersection(start1, end1, start2, end2);
    outputPt(retPt);
}

void testcase08(Solution& sol) {
    cout << "=====Testase 1.2.1 no inetrsaction =====" << endl;

    vector<int> start1 = {0, 0};
    vector<int> end1 = {0, 3};
    vector<int> start2 = {-4, 4};
    vector<int> end2 = {6, 6};

    vector<double> retPt = sol.intersection(start1, end1, start2, end2);
    outputPt(retPt);
}

void testcase09(Solution& sol) {
    cout << "=====Testase 2.1 inetrsaction =====" << endl;

    vector<int> start1 = {3, 0};
    vector<int> end1 = {-3, 0};
    vector<int> start2 = {0, 3};
    vector<int> end2 = {0, -3};

    vector<double> retPt = sol.intersection(start1, end1, start2, end2);
    outputPt(retPt);
}

void testcase10(Solution& sol) {
    cout << "=====Testase 2.2 inetrsaction =====" << endl;

    vector<int> start1 = {2, 2};
    vector<int> end1 = {-2, -1};
    vector<int> start2 = {0, 3};
    vector<int> end2 = {0, -3};

    vector<double> retPt = sol.intersection(start1, end1, start2, end2);
    outputPt(retPt);
}

void testcase11(Solution& sol) {
    cout << "=====Testase 2.2 no inetrsaction =====" << endl;

    vector<int> start1 = {2, 5};
    vector<int> end1 = {-2, 4};
    vector<int> start2 = {0, 3};
    vector<int> end2 = {0, -3};

    vector<double> retPt = sol.intersection(start1, end1, start2, end2);
    outputPt(retPt);
}

void testcase12(Solution& sol) {
    cout << "=====Testase 3 no inetrsaction =====" << endl;

    vector<int> start1 = {2, 2};
    vector<int> end1 = {-2, -2};
    vector<int> start2 = {3, 2};
    vector<int> end2 = {-1, -2};

    vector<double> retPt = sol.intersection(start1, end1, start2, end2);
    outputPt(retPt);
}

void testcase13(Solution& sol) {
    cout << "=====Testase 3 inetrsaction =====" << endl;

    vector<int> start1 = {0, 0};
    vector<int> end1 = {1, -1};
    vector<int> start2 = {0, 0};
    vector<int> end2 = {-1, 1};

    vector<double> retPt = sol.intersection(start1, end1, start2, end2);
    outputPt(retPt);
}

void testcase14(Solution& sol) {
    cout << "=====Testase 3 inetrsaction =====" << endl;

    vector<int> start1 = {-1, -1};
    vector<int> end1 = {-2, -2};
    vector<int> start2 = {-4, -2};
    vector<int> end2 = {6, 2};

    vector<double> retPt = sol.intersection(start1, end1, start2, end2);
    outputPt(retPt);
}

int main (int argc, char* []) 
{
    // Your test case
    Solution sol = Solution();

    testcase01(sol);
    testcase02(sol);
    testcase03(sol);
    testcase04(sol);
    testcase05(sol);
    testcase06(sol);
    testcase07(sol);
    testcase08(sol);
    testcase09(sol);
    testcase10(sol);
    testcase11(sol);
    testcase12(sol);
    testcase13(sol);

    return 0;
}