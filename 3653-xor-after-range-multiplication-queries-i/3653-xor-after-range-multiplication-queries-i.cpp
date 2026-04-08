class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        vector<long long>res(n, 0LL);
        for (int i = 0; i < n; i++) {
            res[i] += nums[i];
        }
        
        int idx = -1;
        for (const auto& query: queries) {
            int l  = query[0], r = query[1], k = query[2], v = query[3];
            idx = l;
            while (idx <= r) {
                res[idx] = (res[idx] * v) % MOD;
                idx += k;
            }
        }

        int ans = res[0];
        for (int i = 1; i < n; i++) {
            ans ^= res[i];
        }

        return ans;
    }
};