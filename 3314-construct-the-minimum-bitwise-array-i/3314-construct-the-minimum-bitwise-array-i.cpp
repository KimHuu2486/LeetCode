class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);

        for (int i = 0; i < (int)nums.size(); i++) {
            int p = nums[i];
            if (p == 2) {            
                ans[i] = -1;
                continue;
            }

            int t = 0;
            int tmp = p;
            while ((tmp & 1) == 1) {
                t++;
                tmp >>= 1;
            }

            // minimal x = p - 2^(t-1)
            long long x = (long long)p - (1LL << (t - 1));
            ans[i] = (int)x;
        }

        return ans;
    }
};