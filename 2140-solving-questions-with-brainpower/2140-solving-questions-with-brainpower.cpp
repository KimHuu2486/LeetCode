class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int nextIdx = i + 1 + questions[i][1];
            long long take = (long long)questions[i][0] + (nextIdx < n ? dp[nextIdx] : 0);
            long long skip = dp[i + 1];
            dp[i] = max(take, skip);
        }
        return dp[0];
    }
};