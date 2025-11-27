class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + nums[i];
        }

        long long ans = LLONG_MIN;

        vector<long long>bestMin(k, LLONG_MAX);
        bestMin[0] = 0;

        for (int b = 1; b <= n; b++) {
            int r = b % k;

            if (bestMin[r] != LLONG_MAX) {
                ans = max(ans, pref[b] - bestMin[r]);
            }

            bestMin[r] = min(bestMin[r], pref[b]);
        }

        return ans;

        return ans;
    }
};