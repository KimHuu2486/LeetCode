class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        vector<int>dp(m, 1);

        auto check = [&](int i, int j) {
            for (int r = 0; r < n; r++) {
                if (strs[r][i] > strs[r][j]) {
                    return false;
                }
            }
            return true;
        };
        int best = 1;
        for (int j = 1; j < m; j++) {
            for (int i = 0; i < j; i++) {
                if (check(i, j)) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
            best = max(best, dp[j]);
        }

        return m - best;
    }
};