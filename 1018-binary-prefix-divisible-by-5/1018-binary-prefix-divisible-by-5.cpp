class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int lastDigit = 0;
        int n = nums.size();
        vector<bool>ans(n, false);

        for (int i = 0; i < n; i++) {
            lastDigit = lastDigit * 2;
            if (nums[i] == 1) {
                lastDigit += 2;
            }
            lastDigit %= 10;
            if (lastDigit == 0 || lastDigit == 5) {
                ans[i] = true;
            }
        }
        return ans;
    }
};