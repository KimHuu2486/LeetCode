class Solution {
public:
    struct point{
        long long maxi, mini;
    };
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long MOD = 1e9 + 7;
        vector<vector<point>>dp(m, vector<point>(n));

        dp[0][0] = {(long long)grid[0][0], (long long)grid[0][0]};

        for (int i = 1; i < m; i++) {
            long long cur = dp[i - 1][0].maxi * grid[i][0];
            dp[i][0] = {cur, cur};
        }

        for (int j = 1; j < n; j++) {
            long long cur = dp[0][j - 1].maxi * grid[0][j];
            dp[0][j] = {cur, cur};
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                long long cur = grid[i][j];
                long long a = dp[i - 1][j].maxi * cur;
                long long b = dp[i - 1][j].mini * cur;
                long long c = dp[i][j - 1].maxi * cur;
                long long d = dp[i][j - 1].mini * cur;

                dp[i][j].maxi = max({a, b, c, d});
                dp[i][j].mini = min({a, b, c, d});
            }
        }

        long long res = dp[m - 1][n - 1].maxi;
        
        return (res < 0) ? -1 : res % MOD;
    }
};