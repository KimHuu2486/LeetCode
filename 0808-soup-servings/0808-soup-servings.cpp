class Solution {
public:
    double dfs(vector<vector<double>>& dp, int A, int B) {
        if (A <= 0 && B > 0)
            return 1;
        if (A <= 0 && B <= 0)
            return 0.5;
        if (A > 0 && B <= 0)
            return 0;
        if (dp[A][B] != -1)
            return dp[A][B];
        double ans = 0.25 * (dfs(dp, A - 4, B) + dfs(dp, A - 3, B - 1) +
                             dfs(dp, A - 2, B - 2) + dfs(dp, A - 1, B - 3));
        dp[A][B] = ans;
        return ans;
    }
    double soupServings(int n) {
        if (n > 5000)
            return 1;
        vector<vector<double>> dp(201, vector<double>(201, -1));
        int N = ceil(n / 25.0);
        return dfs(dp, N, N);
    }
};