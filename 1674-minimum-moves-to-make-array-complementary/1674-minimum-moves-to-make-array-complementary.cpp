class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int>diff(2 * limit + 2, 0);
        for (int i = 0; i < n / 2; i++) {
            int a = min(nums[i], nums[n - 1 - i]);
            int b = max(nums[i], nums[n - 1 - i]);

            diff[2] += 2;
            diff[limit * 2 + 1] -=2;

            diff[a + 1] -=1;
            diff[limit + b + 1] += 1;

            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
        }

        int ans = INT_MAX;
        int cur = 0;
        for (int i = 2; i <= limit * 2; i++) {
            cur += diff[i];
            ans = min(ans, cur);
        }
        return ans;
    }
};