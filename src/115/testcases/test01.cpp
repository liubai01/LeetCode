// // This script is compiled under windows
// g++ test01.cpp -o test01.exe -std=c++0x

#include <iostream>
#include <string>
#include <vector>

#include "../sol.cpp"

int main (int argc, char* []) 
{
    Solution sol = Solution();
    cout << sol.reverseWords("a bb cc d")  << endl;
    return 0;
}