class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n - 2; i++) {
            dp[i][i + 2] = values[i] * values[i + 1] * values[i + 2];
        }
        for (int d = 3; d < n; d++) {
            for (int i = 0; i < n - d; i++) {
                int j = i + d;
                int w = INT_MAX, e = values[i] * values[j];
                for (int k = i + 1; k < j; k++) {
                    w = min(w, e * values[k] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = w;
            }
        }
        return dp[0][n - 1];
    }
};