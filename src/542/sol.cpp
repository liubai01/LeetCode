#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        // initialize
        int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int xmax, ymax;
        vector<vector<int>> retMat;
        vector<vector<int>> visited;
        queue<pair<int, int>> q;

        retMat.clear();

        // boundary case
        if (matrix.empty()) return retMat;
        xmax = matrix.size();
        ymax = matrix[0].size();

        // search zeros as starter and initialize the matrix
        for (int i = 0; i < xmax; ++i) {
            retMat.push_back(vector<int>());
            for (int j = 0; j < ymax; ++ j) {
                if (matrix[i][j] == 0) {
                    q.push(pair<int, int>(i, j));
                    retMat[i].push_back(0);
                } else {
                    retMat[i].push_back(10001);
                }
            }
        }

        while(!q.empty()){
            pair<int, int> nowPair = q.front();
            int i = nowPair.first;
            int j = nowPair.second;
            int vistiedValue = matrix[i][j];
            int visitedDist = retMat[i][j];
            q.pop();

            for (int d = 0; d < 4; ++d) {
                int x = i + dir[d][0];
                int y = j + dir[d][1];
                if (x >= 0 && x < xmax && y >= 0 && y < ymax) {
                    int frontierValue = matrix[x][y];
                    if (frontierValue == 1) {
                        bool fVisted = retMat[x][y] <= 10000;
                        retMat[x][y] = min(retMat[x][y], visitedDist + 1);
                        if (!fVisted) {
                            q.push(pair<int, int>(x, y));
                        }
                    }

                }
            }
        }
        return retMat;
    }
};