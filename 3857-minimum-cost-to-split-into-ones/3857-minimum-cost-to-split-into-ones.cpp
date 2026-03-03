class Solution {
public:
    int minCost(int n) {
        vector<int>dp(n + 1, INT_MAX);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            int a = 1, b = i - 1;
            while (a <= b) {
                dp[i] = min(dp[i], dp[a] + dp[b] + a * b);
                a++; b--;
            }
        }
        return dp[n];
    }
};