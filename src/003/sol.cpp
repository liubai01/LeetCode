class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        bool lastOccur[256];
        for (int i = 0; i < 256; ++i) {
            lastOccur[i] = false;
        }

        int startIdx = 0;
        int maxLen = 1;
        lastOccur[s[startIdx]] = true;

        for (int i = 1; i < s.length(); ++i) {
            char nowChar = s[i];
            if (lastOccur[nowChar]) {
                maxLen = max(maxLen, i - startIdx);
                for (int j = startIdx; j <= i; ++j) {
                    lastOccur[s[j]] = false;
                    startIdx = j + 1;
                    if (s[j] == nowChar) {
                        break;
                    }
                }
            }
            lastOccur[nowChar] = true;
        }
        maxLen = max(maxLen, (int) s.length() - startIdx);
        return maxLen;
    }
};