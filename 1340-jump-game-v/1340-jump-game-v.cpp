class Solution {
public:
    int solve(vector<int>& arr, int d, int i, vector<int>& dp) {
        if (dp[i] != -1)
            return dp[i];
        int cnt = 1;

        // Move left
        for (int j = i - 1; j >= 0 && i - j <= d; j--) {
            if (arr[i] > arr[j]) {
                cnt = max(cnt, 1 + solve(arr, d, j, dp));
            } else
                break;
        }

        // Move right
        for (int j = i + 1; j < arr.size() && j - i <= d; j++) {
            if (arr[i] > arr[j]) {
                cnt = max(cnt, 1 + solve(arr, d, j, dp));
            } else
                break;
        }

        return dp[i] = cnt;
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(arr, d, i, dp));
        }

        return ans;
    }
};