class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long val[3];
        for (int i = 0; i < n; i++) {
            val[0]  = 0LL + nums[i] -  k;
            val[1] = nums[i];
            val[2] = 0LL + nums[i] + k;
            for (int j = 0; j < 3; j++) {
                int left = lower_bound(nums.begin(), nums.end(), val[j] - k) - nums.begin();
                int right = upper_bound(nums.begin(), nums.end(), val[j] + k) - nums.begin();
                int mid = lower_bound(nums.begin() + left, nums.begin() + right, val[j])    -nums.begin();
                int same = 0;
                while (mid < n && nums[mid] == val[j]) {
                    mid++;
                    same++;
                }
                ans = max(ans, same + min(numOperations, right - left - same));
            }
        }
        return ans;
    }
};