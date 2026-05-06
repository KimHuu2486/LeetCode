class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();
        vector<vector<char>>rotatedBox(n, vector<char>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rotatedBox[j][m - 1 - i] = boxGrid[i][j];
            }
        }

        for (int j = 0; j < m; j++) {
            int bottom = n - 1;
            for (int i = n - 1; i >= 0; i--) {
                if (rotatedBox[i][j] == '*') {
                    bottom = i - 1;
                }
                else if (rotatedBox[i][j] == '#') {
                    if (bottom != i) {
                        rotatedBox[bottom][j] = rotatedBox[i][j];
                        rotatedBox[i][j] = '.';
                    }
                    bottom--;
                }
            }
        }

        return rotatedBox;
    }
};