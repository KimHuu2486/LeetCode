class Solution {
public:
    int numberOfWays(int n, int x) {
        const int MOD = 1e9 + 7;
        vector<int> powers;
        for (int i = 1; i <= n; i++) {
            long long p = i;
            for (int j = 1; j < x; j++) {
                p *= i;
            }
            if (p > n)
                break;
            powers.push_back(p);
        }
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        for (int p : powers) {
            for (int s = n; s >= p; s--) {
                dp[s] = (dp[s] + dp[s - p]) % MOD;
            }
        }
        return dp[n];
    }
};