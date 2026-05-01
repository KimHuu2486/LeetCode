class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long ans = 0LL;
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            ans += nums[i] * i;
        }

        long long prev = ans;
        for (int i = 1; i < n; i++) {
            long long curr = prev + sum - n * nums[n - i];
            ans = max(ans, curr);
            prev = curr;
        }

        return ans;
    }
};