#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str_gen(int l_num, int r_num) {
    string ret_s = "";
    for (int i = 0; i < l_num; ++i) {
        ret_s += "(";
    }
    for (int i = 0; i < r_num; ++i) {
        ret_s += ")";
    }
    return ret_s;
}

vector<string> DFS(int l_num, int r_num) {
    vector<string> ret_vec;
    if(l_num == 1) {
        ret_vec.push_back(str_gen(1, r_num));
        return ret_vec;
    } else {
        l_num -= 1;
        for(int use_r_num = 0; use_r_num < r_num -  l_num + 1; ++use_r_num) {
            vector<string> sub_strs = DFS(l_num, r_num - use_r_num);
            for (int i = 0; i < sub_strs.size(); ++i) {
                string s = sub_strs[i];
                ret_vec.push_back(str_gen(1, use_r_num) + s);
            }
        }
    }
    return ret_vec;
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        return DFS(n, n);
    }
};