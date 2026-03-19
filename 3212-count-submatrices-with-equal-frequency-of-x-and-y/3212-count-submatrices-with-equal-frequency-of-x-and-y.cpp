class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> prefixX(m, vector<int>(n, 0));
        vector<vector<int>> prefixY(m, vector<int>(n, 0));

        if (grid[0][0] == 'X') {
            prefixX[0][0] = 1;
        } else if (grid[0][0] == 'Y') {
            prefixY[0][0] = 1;
        }

        int ans = 0;
        for (int i = 1; i < m; i++) {
            prefixX[i][0] = prefixX[i - 1][0];
            prefixY[i][0] = prefixY[i - 1][0];
            if (grid[i][0] == 'X') {
                prefixX[i][0]++;
            } else if (grid[i][0] == 'Y') {
                prefixY[i][0]++;
            }

            if (prefixX[i][0] > 0 && prefixX[i][0] == prefixY[i][0])
                ans++;
        }

        for (int j = 1; j < n; j++) {
            prefixX[0][j] = prefixX[0][j - 1];
            prefixY[0][j] = prefixY[0][j - 1];
            if (grid[0][j] == 'X') {
                prefixX[0][j]++;
            } else if (grid[0][j] == 'Y') {
                prefixY[0][j]++;
            }

            if (prefixX[0][j] > 0 && prefixX[0][j] == prefixY[0][j])
                ans++;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                prefixX[i][j] = prefixX[i - 1][j] + prefixX[i][j - 1] -
                                prefixX[i - 1][j - 1];
                prefixY[i][j] = prefixY[i - 1][j] + prefixY[i][j - 1] -
                                prefixY[i - 1][j - 1];

                if (grid[i][j] == 'X') {
                    prefixX[i][j]++;
                } else if (grid[i][j] == 'Y') {
                    prefixY[i][j]++;
                }

                if (prefixX[i][j] > 0 && prefixX[i][j] == prefixY[i][j])
                    ans++;
            }
        }

        return ans;
    }
};