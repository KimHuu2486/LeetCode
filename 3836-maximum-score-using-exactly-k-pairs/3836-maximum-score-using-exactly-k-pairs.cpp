class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();

        const long long INF = 1e16;
        vector<vector<long long>> dp(n, vector<long long>(m, -INF));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = (long long)nums1[i] * nums2[j];
            }
        }

        for (int t = 2; t <= k; t++) {
            vector<vector<long long>> prevMax(
                n + 1, vector<long long>(m + 1, -INF));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    prevMax[i + 1][j + 1] =
                        max({dp[i][j], prevMax[i][j + 1], prevMax[i + 1][j]});
                }
            }

            vector<vector<long long>> nextDp(n, vector<long long>(m, -INF));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (prevMax[i][j] != -INF) {
                        nextDp[i][j] = (long long)nums1[i] * nums2[j] + prevMax[i][j];
                    }
                }
            }

            dp = move(nextDp);
        }

        long long ans = -INF;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};