class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        const int MOD = 1e9 + 7;
        
        vector<vector<int>>dp(n, vector<int>(k, 0));

        for (int i = 0; i < m ; i++) {
            vector<vector<int>>new_dp(n, vector<int>(k, 0));

            for (int j = 0; j < n; j++) {
                int val = grid[i][j] % k;

                if (i == 0 && j == 0) {
                    new_dp[j][val] = 1;
                    continue;
                }

                for (int r = 0; r < k; r++) {
                    long long ways = 0;
                    if (i > 0) {
                        ways += dp[j][r];
                    }
                    if (j > 0) {
                        ways += new_dp[j - 1][r];
                    }
                    if (ways == 0) {
                        continue;
                    }
                    int nr = (val + r) % k;
                    new_dp[j][nr] = (new_dp[j][nr] + ways) % MOD;
                }
                
            }
            swap(dp, new_dp);
        }
        return dp[n-1][0];
    }
};