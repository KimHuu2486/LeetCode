class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> mp;
        for (int& x : power)
            mp[x]++;
        vector<int> value;
        for (auto& it : mp)
            value.push_back(it.first);
        sort(value.begin(), value.end());
        int n = value.size();
        vector<long long> dp(n);
        dp[0] = (long long)value[0] * mp[value[0]];
        for (int i = 1; i < n; i++) {
            long long take = value[i] * mp[value[i]];
            int prev = upper_bound(value.begin(), value.end(), value[i] - 3) -
                       value.begin() - 1;
            if (prev >= 0) {
                take += dp[prev];
            }
            dp[i] = max(dp[i - 1], take);
        }
        return dp[n - 1];
    }
};