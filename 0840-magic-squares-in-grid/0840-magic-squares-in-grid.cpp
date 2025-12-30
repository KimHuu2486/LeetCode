class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m < 3 || n < 3) return 0;

        int ans = 0;

        for (int i = 0; i < m - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                if (grid[i + 1][j + 1] != 5) {
                    continue;
                }

                bool ok = true;
                vector<bool>visited(10, false);
                for (int r = i; r < i + 3; r++) {
                    for (int c = j; c < j + 3; c++) {
                        int cur= grid[r][c];
                        if (cur < 1 || cur > 9 || visited[cur]) {
                            ok = false;
                            break;
                        }
                        visited[cur] = true;
                    }
                    if (!ok) {
                        break;
                    }
                }
                if (!ok) {
                    continue;
                }

            if (grid[i][j] + grid[i][j+1] + grid[i][j+2] != 15) continue;
            if (grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2] != 15) continue;
            if (grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2] != 15) continue;

            if (grid[i][j] + grid[i+1][j] + grid[i+2][j] != 15) continue;
            if (grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1] != 15) continue;
            if (grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2] != 15) continue;

            if (grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] != 15) continue;
            if (grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] != 15) continue;

            ans += 1;
            }
        }

        return ans;
    }
};