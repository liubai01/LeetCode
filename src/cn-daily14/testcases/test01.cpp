// // This script is compiled under windows
// g++ test01.cpp -o test01.exe -std=c++0x

#include <iostream>
#include <string>
#include <vector>

#include "../sol.cpp"

int main (int argc, char* []) 
{
    Solution sol = Solution();
    vector<string> ret_vec = sol.generateParenthesis(3) ;

    for(int i = 0; i < ret_vec.size(); ++i) {
        cout << ret_vec[i] << endl;
    }

    return 0;
}