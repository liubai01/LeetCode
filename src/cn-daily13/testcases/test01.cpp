// // This script is compiled under windows
// g++ test01.cpp -o test01.exe -std=c++0x

#include <iostream>
#include <string>

#include "../sol.cpp"

int main (int argc, char* []) 
{
	Solution s = Solution();
	cout << s.movingCount(2, 3, 2) << endl;
	return 0;
}