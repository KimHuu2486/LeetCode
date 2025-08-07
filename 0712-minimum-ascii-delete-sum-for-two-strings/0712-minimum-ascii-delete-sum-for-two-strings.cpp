class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + s2[i - 1];
        }
        for (int i = 1; i <= m; i++) {
            int prev = dp[0];
            dp[0] += s1[i - 1];
            for (int j = 1; j <= n; j++) {
                int temp = dp[j];
                if (s1[i - 1] == s2[j - 1]) {
                    dp[j] = prev;
                } else {
                    dp[j] = min(dp[j] + s1[i - 1], dp[j - 1] + s2[j - 1]);
                }
                prev = temp;
            }
        }
        return dp[n];
    }
};