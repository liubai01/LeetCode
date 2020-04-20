#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n)); // visted blocks
        int cnter = 0; // cnter of island
        int dirs[4][2] = {{-1, 0}, {+1, 0}, {0, +1}, {0, -1}};

        // initialize all blocks as unvisited
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                visited[x][y] = false;
            }
        }

        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                if (!visited[x][y]) {
                    visited[x][y] = true;
                    if (grid[x][y] == '1') {
                        queue<int> qX;
                        queue<int> qY;
                        qX.push(x);
                        qY.push(y);

                        cnter += 1;

                        // clean near lands
                        while (!qX.empty()) {
                            int nowX = qX.front();
                            int nowY = qY.front();

                            qX.pop();
                            qY.pop();

                            for (int dIdx = 0; dIdx < 4; ++dIdx) {
                                int toX = nowX + dirs[dIdx][0];
                                int toY = nowY + dirs[dIdx][1];
                                if (toX >= 0 && toX < m && toY >= 0 && toY < n && grid[toX][toY] == '1' && !visited[toX][toY]) {
                                    visited[toX][toY] = true;
                                    qX.push(toX);
                                    qY.push(toY);
                                }
                            }
                        }
                    }
                    
                }
            }
        }
        return cnter;
    }
};