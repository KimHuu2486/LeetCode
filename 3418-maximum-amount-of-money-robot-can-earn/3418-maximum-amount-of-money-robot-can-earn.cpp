class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(3, -1e9)));
        dp[0][0][0] = coins[0][0];
        if (coins[0][0] < 0) {
            dp[0][0][1] = 0;
        } else {
            dp[0][0][1] = coins[0][0];
        }
        dp[0][0][2] = dp[0][0][1];

        // top row
        for (int i = 1; i < m; i++) {
            dp[i][0][0] = dp[i - 1][0][0] + coins[i][0];
            dp[i][0][1] = max(dp[i - 1][0][1] + coins[i][0], dp[i - 1][0][0]);
            dp[i][0][2] = max(dp[i - 1][0][2] + coins[i][0], dp[i - 1][0][1]);
        }
        // left col
        for (int j = 1; j < n; j++) {
            dp[0][j][0] = dp[0][j - 1][0] + coins[0][j];
            dp[0][j][1] = max(dp[0][j - 1][1] + coins[0][j], dp[0][j - 1][0]);
            dp[0][j][2] = max(dp[0][j - 1][2] + coins[0][j], dp[0][j - 1][1]);
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j][0] =
                    max(dp[i - 1][j][0], dp[i][j - 1][0]) + coins[i][j];
                dp[i][j][1] =
                    max(max(dp[i - 1][j][1], dp[i][j - 1][1]) + coins[i][j],
                        max(dp[i][j - 1][0], dp[i - 1][j][0]));
                dp[i][j][2] =
                    max(max(dp[i - 1][j][2], dp[i][j - 1][2]) + coins[i][j],
                        max(dp[i][j - 1][1], dp[i - 1][j][1]));
            }
        }

        return max(dp[m - 1][n - 1][0],
                   max(dp[m - 1][n - 1][1], dp[m - 1][n - 1][2]));
    }
};