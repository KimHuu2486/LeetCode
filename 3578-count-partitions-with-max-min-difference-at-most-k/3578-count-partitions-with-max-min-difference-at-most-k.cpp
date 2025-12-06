class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0LL);
        vector<long long> prefSum(n + 1, 0LL);
        dp[0] = 1;
        prefSum[0] = 1;

        deque<int> min_Q, max_Q;
        int left = 0;

        for (int i = 1; i <= n; i++) {
            int x = nums[i - 1];

            while (!min_Q.empty() && nums[min_Q.back()] >= x) {
                min_Q.pop_back();
            }
            min_Q.push_back(i - 1);

            while (!max_Q.empty() && nums[max_Q.back()] <= x) {
                max_Q.pop_back();
            }
            max_Q.push_back(i - 1);

            while (!min_Q.empty() && !max_Q.empty() && nums[max_Q.front()] - nums[min_Q.front()] > k) {
                if (min_Q.front() == left) min_Q.pop_front();
                if (max_Q.front() == left) max_Q.pop_front();
                left++;
            }

            long long ways;
            if (left == 0) {
                ways = prefSum[i - 1];
            }
            else {
                ways = (prefSum[i - 1] - prefSum[left- 1] + MOD) % MOD;
            }
            dp[i] = ways;
            prefSum[i] = (prefSum[i - 1] + dp[i]) % MOD;
        }
        return dp[n];
    }
};