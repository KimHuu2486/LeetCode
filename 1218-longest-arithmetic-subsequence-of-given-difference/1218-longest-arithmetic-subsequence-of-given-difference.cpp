class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        const int OFFSET = 10000;
        const int SIZE = 20003;
        vector<int> dp(SIZE, 0);
        int ans = 1;

        for (int val : arr) {
            int idx = val + OFFSET;
            int prevIdx = idx - difference;
            if (prevIdx >= 0 && prevIdx < SIZE) {
                dp[idx] = dp[prevIdx] + 1;
            } else {
                dp[idx] = 1;
            }
            ans = max(ans, dp[idx]);
        }
        return ans;
    }
};