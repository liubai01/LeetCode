// // This script is compiled under windows
// g++ test01.cpp -o test01.exe -std=c++0x

#include <iostream>
#include <string>
#include <vector>

#include "../sol.cpp"

int main (int argc, char* []) 
{
    Twitter* obj = new Twitter();
    obj->postTweet(1,2);
    vector<int> param_2 = obj->getNewsFeed(1);
    cout << "1's message" << endl;
    for (auto iter = param_2.begin(); iter < param_2.end(); ++ iter) {

        cout << *iter << endl;
    }

    obj->follow(1, 2);
    obj->postTweet(2, 6);
    obj->postTweet(2, 2);
    obj->postTweet(2, 8);
    obj->postTweet(2, 23);
    // obj->unfollow(1, 2);


    vector<int> param_3 = obj->getNewsFeed(1);
    cout << "1's message" << endl;
    for (auto iter = param_3.begin(); iter < param_3.end(); ++ iter) {

        cout << *iter << endl;
    }
	return 0;
}