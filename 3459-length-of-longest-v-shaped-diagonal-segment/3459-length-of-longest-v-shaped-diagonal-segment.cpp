class Solution {
public:
    const vector<vector<int>> DIRS = {{-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> memo(
            m, vector<vector<int>>(n, vector<int>(1 << 3, -1)));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 1)
                    continue;
                for (int dir = 0; dir < 4; dir++) {
                    ans = max(ans, dfs(i, j, dir, 1, 2, grid, memo) + 1);
                }
            }
        }
        return ans;
    }
    int dfs(int i, int j, int dir, int canTurn, int target,
            vector<vector<int>>& grid, vector<vector<vector<int>>>& memo) {
        int m = grid.size(), n = grid[0].size();
        int ni = i + DIRS[dir][0];
        int nj = j + DIRS[dir][1];
        if (ni < 0 || ni >= m || nj < 0 || nj >= n || grid[ni][nj] != target) {
            return 0;
        }
        int mask = (dir << 1) | canTurn;
        if (memo[i][j][mask] != -1)
            return memo[i][j][mask];
        int best = dfs(ni, nj, dir, canTurn, 2 - target, grid, memo) + 1;
        if (canTurn) {
            int ndir = (dir + 1) % 4;
            best = max(best, dfs(ni, nj, ndir, 0, 2 - target, grid, memo) + 1);
        }
        return memo[i][j][mask] = best;
    }
};