#include <vector>

using namespace std;

int dp[101][10001];

class Solution {
public:
    int superEggDrop(int K, int N) {
        // initialize
        for(int i = 1; i <= K; ++i) {
            for(int j = 0; j <= N; ++j) {
                // only one egg left: conservative
                if (i == 1) {
                    dp[i][j] = j;
                } else if (j == 1) { // only one left left: trivial
                    dp[i][j] = 1;
                } else if (j == 0) {
                	dp[i][j] = 0;
                } else {
                	dp[i][j] = -1;
                }
                
            }
        }
        return dpSolve(K, N, K, N);
    }

	int dpSolve(int k, int n, int K, int N) {
	    int now_min = 9999999;
	    int low_drop = 1;
	    int high_drop = n;
	    int thre = 10;

	    // memorized
	    if (dp[k][n] != -1) return dp[k][n];

	    while (high_drop - low_drop > thre) {
	    	int drop_lvl = (low_drop + high_drop) / 2;
	        int broken_times = 1 + (dp[k - 1][drop_lvl -1] == -1 ? dpSolve(k - 1, drop_lvl - 1, K, N): dp[k - 1][drop_lvl -1]);
	        int unbroken_times = 1 + (dp[k][n - drop_lvl] == -1 ? dpSolve(k, n - drop_lvl, K, N): dp[k][n - drop_lvl]);
	        int worse_case = max(broken_times, unbroken_times);

	        if (worse_case < now_min) {
	            now_min = worse_case;
	        }

	        if (broken_times > unbroken_times) {
    		    high_drop = drop_lvl;
	        } else {
	        	low_drop = drop_lvl;
	        }
	    }
	    for (int drop_lvl = max(1, low_drop - 1);  drop_lvl <= min(high_drop + 1, n); ++drop_lvl){
	        int broken_times = 1 + (dp[k - 1][drop_lvl -1] == -1 ? dpSolve(k - 1, drop_lvl - 1, K, N): dp[k - 1][drop_lvl -1]);
	        int unbroken_times = 1 + (dp[k][n - drop_lvl] == -1 ? dpSolve(k, n - drop_lvl, K, N): dp[k][n - drop_lvl]);
	        int worse_case = max(broken_times, unbroken_times);
	        if (worse_case < now_min) {
	            now_min = worse_case;
	        }

	        if (broken_times > unbroken_times) {
    		    dp[k][n] = now_min;
	    		return dp[k][n];
	        }
	      
	    }
	    dp[k][n] = now_min;
	    return dp[k][n];
	}

};