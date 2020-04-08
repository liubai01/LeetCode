// // This script is compiled under windows
// g++ test01.cpp -o test01.exe -std=c++0x

#include <iostream>
#include <string>

#include "../sol_dp.cpp"

using namespace std;

int main (int argc, char* []) 
{
	// string s = "aabbcdaaabbbcccbbbaaaacvbbbvcaaqwertyuiopoiuytrewqbcdaaabbaaabbaaaacccaa";
	string s = "";
	Solution sol = Solution();

	cout << sol.longestPalindrome(s) << endl;

	return 0;
}