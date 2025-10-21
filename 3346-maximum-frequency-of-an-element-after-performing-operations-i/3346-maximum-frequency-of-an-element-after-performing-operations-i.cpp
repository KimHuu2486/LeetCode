class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        for (int val = nums[0]; val <= nums[n - 1]; val++) {
            int left =
                lower_bound(nums.begin(), nums.end(), val - k) - nums.begin();
            int right =
                upper_bound(nums.begin(), nums.end(), val + k) - nums.begin();
            int mid =
                lower_bound(nums.begin() + left, nums.begin() + right, val) -
                nums.begin();
            int cnt = 0;
            while (mid < right && nums[mid] == val) {
                cnt++;
                mid++;
            }
            ans = max(ans, cnt + min(numOperations, right - left - cnt));
        }
        return ans;
    }
};