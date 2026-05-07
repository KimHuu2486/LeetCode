class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n), suffix(n), ans(n);

        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i - 1], nums[i]);
        }

        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = min(suffix[i + 1], nums[i]);
        } 

        ans[n - 1] = prefix[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (prefix[i] > suffix[i + 1]) {
                ans[i] = ans[i + 1];
            }
            else {
                ans[i] = prefix[i];
            }
        }

        return ans;
    }
};