class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int left = 0, right = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        vector<int>ans(n);

        for (int i = 0; i < n; i++) {
            right -= nums[i];
            ans[i] = abs(left - right);
            left += nums[i];
        }

        return ans;
    }
};