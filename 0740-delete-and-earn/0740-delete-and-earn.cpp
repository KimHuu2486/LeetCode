class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> value(n, 0);
        for (int num : nums) {
            value[num] += num;
        }
        vector<int> dp(n, 0);
        dp[1] = value[1];
        dp[2] = max(value[1], value[2]);
        for (int i = 3; i < n; i++) {
            dp[i] = max(dp[i - 1], value[i] + dp[i - 2]);
        }
        return dp[n - 1];
    }
};