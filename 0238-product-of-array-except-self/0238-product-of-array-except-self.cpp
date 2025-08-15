class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i];
        }
        vector<long long> suffix(n);
        suffix.back() = nums.back();
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i];
        }
        vector<int> ans(n);
        ans[0] = suffix[1];
        ans.back() = prefix[n - 2];
        for (int i = 1; i < n - 1; i++) {
            ans[i] = prefix[i - 1] * suffix[i + 1];
        }
        return ans;
    }
};