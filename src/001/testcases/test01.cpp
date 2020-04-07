// // This script is compiled under windows
// g++ test01.cpp -o test01.exe -std=c++0x

#include <iostream>
#include <string>
#include <vector>

#include "../sol_hash.cpp"

int main (int argc, char* []) 
{
	vector<int> v;
	v.push_back(6);
	v.push_back(3);
	v.push_back(5);
	v.push_back(1);

	Solution s = Solution();
	vector<int> ret_v = s.twoSum(v, 8);

	cout << ret_v[0] << " " << ret_v[1] << endl;

	return 0;
}