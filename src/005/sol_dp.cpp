#include <string>

#define MAX_PLEN 1000

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        // dynamic programming method
        int str_len = s.length();
        // boundary cases
        if (str_len == 1) 
            return s;
        else if (str_len == 2) {
            if (s[0] == s[1]) return s;
            else return s.substr(0, 1);
        } else {
            bool dp_s[MAX_PLEN][MAX_PLEN];
            int max_len = 1;
            int max_start_idx = 0;

            // initial status
            // For string with length 1
            for (int i = 0; i < str_len; ++i) {
                dp_s[0][i] = true;
            }
            // For string with length 2
            for (int i = 0; i < str_len  - 1; ++i) {
                bool is_pal = s[i] == s[i + 1];
                dp_s[1][i] = is_pal;

                if (is_pal && max_len <= 1) {
                    max_len = 2;
                    max_start_idx = i;
                }
            }
            // For string with length 2+
            for (int i = 2; i < min(str_len, MAX_PLEN); ++i) {
                for (int j = 0; j < str_len - i; ++j) {
                        bool is_pal = dp_s[i - 2][j + 1] * (s[j] == s[j + i]);
                        dp_s[i][j] = is_pal;
                        if (is_pal && max_len <= i){
                            max_len = i + 1;
                            max_start_idx = j;
                        }
                }
            }
            return s.substr(max_start_idx, max_len);
        }
    }
};