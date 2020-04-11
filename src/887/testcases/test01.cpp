// // This script is compiled under windows
// g++ test01.cpp -o test01.exe -std=c++0x

#include <iostream>
#include <string>

#include "../sol.cpp"
using namespace std;

int main (int argc, char* []) 
{
	Solution sol = Solution();
	cout << sol.superEggDrop(4, 10000) << endl;
	cout << "===========" << endl;
	return 0;
}