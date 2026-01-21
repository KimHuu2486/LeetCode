class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, -1);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 2) {
                continue;
            }

            long long tmp = 1LL * nums[i];
            int t = 0;
            while ((tmp & 1) == 1) {
                t++;
                tmp >>= 1;
            }

            ans[i] = (long long)nums[i] - (1LL << (t - 1));
        }

        return ans;
    }
};