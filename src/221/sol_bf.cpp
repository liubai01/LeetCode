class Solution {
public:
    bool isSquare(vector<vector<char>>& matrix, int x, int y, int size) {
        // pivot is at left-upper corner
        for (int i = x; i < x + size; ++i) {
            for (int j = y; j < y + size; ++j) {
                if (matrix[i][j] == '0') return false;
            }
        }
        return true;
    }

    int bruteForce(vector<vector<char>>& matrix, int xMin, int xMax, int yMin, int yMax) {
        int maxSize = 0;
        for (int i = xMin; i <= xMax; ++i) {
            for (int j = yMin; j <= yMax; ++j) {
                for (int s = maxSize + 1; s <= min(xMax - i + 1, yMax - j + 1); ++s) {
                    if (isSquare(matrix, i, j, s)) {
                        maxSize = s;
                    } 
                }
            }
        }
        return maxSize;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;

        int xMax = matrix.size() - 1;
        int yMax = matrix[0].size() - 1;

        int retS = bruteForce(matrix, 0, xMax, 0, yMax);

        return retS * retS;
    }
};