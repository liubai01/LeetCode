#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> ret_ss;
        string ret_s = "";

        bool is_first_word = true;
        bool is_reading_word = false;
        int word_start_p = -1;
        int word_ret_p = 0;

        for(int s_p = 0; s_p < s.length(); ++s_p) {
            if (s[s_p] == ' ') {
                if (is_reading_word) {
                    // output the word here
                    ret_ss.push_back(s.substr(word_start_p, s_p - word_start_p));
                    word_ret_p = s_p;
                }
                is_reading_word = false;
            } else {
                if (!is_reading_word) {
                    word_start_p = s_p;
                }
                is_reading_word = true;
            }
        }
        if (word_start_p >= word_ret_p && word_start_p != -1) {
            ret_ss.push_back(s.substr(word_start_p));
        }
        while (!ret_ss.empty()) {
            if (is_first_word){
                is_first_word = false;
            } else{
                ret_s += " ";
            }
            ret_s += ret_ss.back();
            ret_ss.pop_back();
         }

        return ret_s;
    }
};