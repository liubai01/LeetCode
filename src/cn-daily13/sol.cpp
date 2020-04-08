#include <iostream>
#include <string>
#include  <queue>

using namespace std;

class Pos {
public:
    int x;
    int y;
    Pos(int x, int y) {
        this->x = x; 
        this->y = y;
    };
    int CalSum(){
        int ret = 0;
        int tmp_x = this->x;
        int tmp_y = this->y;

        while (tmp_x > 0) { ret += tmp_x % 10; tmp_x = tmp_x / 10;}
        while (tmp_y > 0) { ret += tmp_y % 10; tmp_y = tmp_y / 10;}

        return ret;
    };
};


class Solution {
public:
    int movingCount(int m, int n, int k) {
        int cnter;
        bool visited[m][n];
        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<Pos> q;
        
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                visited[x][y] = false;
            }
        }
        q.push(Pos(0, 0));
        visited[0][0] = true;
        cnter = 1;

        while(!q.empty()){
            Pos ret = q.front();
            q.pop();

            for (int d = 0; d < 4; ++d) {
                int new_x = ret.x + dir[d][0];
                int new_y = ret.y + dir[d][1];
                
                bool in_border = new_x >= 0 && new_x < m && new_y >= 0 && new_y < n;
                if (in_border) {
                    Pos newPos = Pos(new_x, new_y);
                    if( !visited[new_x][new_y] && newPos.CalSum()<= k){
                        visited[new_x][new_y]  = true;
                        q.push(newPos);
                        cnter += 1;
                    }
                }
            }

        }

        return cnter;
    }
};