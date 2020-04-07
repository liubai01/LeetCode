#include <string>

#define MAX_PLEN 1000

using namespace std;

bool isPalindrome(string s){
    int str_len = s.length();
    bool isPal = true;

    for(int i = 0; i < str_len / 2; ++i) {
        if (s[i] != s[str_len - i - 1]) {
            isPal = false;
        }
    }
    return isPal;
}

class Solution {
public:
    string longestPalindrome(string s) {
        // baseline brute force method
        int str_len = s.length();
        int max_len = 1;
        int max_start_idx = 0;

        for(int start_idx = 0; start_idx < str_len - max_len; ++start_idx){
            for(int substr_len = max_len + 1; substr_len <= MAX_PLEN; ++substr_len) {
                    int end_idx = start_idx + substr_len;
                    if (end_idx > str_len)  break;
                    if (isPalindrome(s.substr(start_idx, substr_len))) {
                        max_len = substr_len;
                        max_start_idx = start_idx;
                    }
            }
        }
        return s.substr(max_start_idx, max_len);
    }
};