class Solution {
public:
    int cnt0(const string& s) {
        int cnt = 0;
        for (const char& c : s) {
            if (c == '0')
                cnt++;
        }
        return cnt;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (const string& s : strs) {
            int zeroes = cnt0(s);
            int ones = s.size() - zeroes;
            for (int j = m; j >= zeroes; j--) {
                for (int k = n; k >= ones; k--) {
                    dp[j][k] = max(dp[j][k], 1 + dp[j - zeroes][k - ones]);
                }
            }
        }
        return dp[m][n];
    }
};