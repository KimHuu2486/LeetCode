class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long target = sum % p;
        
        if (target == 0) 
            return 0;

        long long prefix = 0;
        int res = INT_MAX;
        unordered_map<int,int>mp;
        mp[0] = -1;

        for (int i = 0; i < nums.size(); i++) {
            prefix = (prefix + nums[i]) % p;
            int need = (prefix - target + p) % p;

            if (mp.count(need)) {
                res = min(res, i - mp[need]);
            }

            mp[prefix] = i;
        }
        
        return res == nums.size() ? -1 : res;
    }
};