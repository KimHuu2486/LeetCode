class Solution {
public:
    int mininumArea(const vector<vector<int>>& grid) {
        int left = INT_MAX, right = INT_MIN, top = INT_MIN, bottom = INT_MAX;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    left = min(left, j);
                    right = max(right, j);
                    top = max(top, i);
                    bottom = min(bottom, i);
                }
            }
        }
        if (right == INT_MIN)
            return 0;
        return (right - left + 1) * (top - bottom + 1);
    }
    vector<vector<int>> rotateRight(const vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][m - 1 - i] = grid[i][j];
            }
        }
        return ans;
    }
    int minimumSum(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        for (int k = 0; k < 4; k++) {
            int m = grid.size(), n = grid[0].size();
            for (int i = 1; i < m; i++) {
                int a1 = mininumArea(
                    vector<vector<int>>(grid.begin(), grid.begin() + i));

                for (int j = 1; j < n; j++) {
                    vector<vector<int>> part2(m - i, vector<int>(j));
                    vector<vector<int>> part3(m - i, vector<int>(n - j));
                    for (int r = 0; r < m - i; r++) {
                        for (int c = 0; c < j; c++)
                            part2[r][c] = grid[i + r][c];
                        for (int c = j; c < n; c++)
                            part3[r][c - j] = grid[i + r][c];
                    }
                    int a2 = mininumArea(part2);
                    int a3 = mininumArea(part3);
                    ans = min(ans, a1 + a2 + a3);
                }
                for (int i2 = i + 1; i2 < m; i2++) {
                    vector<vector<int>> part2(grid.begin() + i,
                                              grid.begin() + i2);
                    vector<vector<int>> part3(grid.begin() + i2, grid.end());
                    int a2 = mininumArea(part2);
                    int a3 = mininumArea(part3);
                    ans = min(ans, a1 + a2 + a3);
                }
            }
            grid = rotateRight(grid);
        }
        return ans;
    }
};