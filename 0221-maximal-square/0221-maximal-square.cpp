class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxSquare = 0;
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = matrix[i][j] - '0';
                maxSquare = max(maxSquare, dp[i][j]);
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (dp[i][j] == 1) {
                    dp[i][j] =
                        min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) +
                        1;
                    maxSquare = max(maxSquare, dp[i][j]);
                }
            }
        }
        return maxSquare * maxSquare;
    }
};