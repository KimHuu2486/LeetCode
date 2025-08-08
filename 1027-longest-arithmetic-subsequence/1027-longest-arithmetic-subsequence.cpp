class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int Min = *min_element(nums.begin(), nums.end());
        int Max = *max_element(nums.begin(), nums.end());
        vector<int> mp(501, 0);
        int ans = 2;
        for (int diff = Min - Max + 1; diff < Max - Min; diff++) {
            fill(mp.begin(), mp.end(), 0);
            for (int val : nums) {
                if (val - diff >= 0 && val - diff <= 500) {
                    mp[val] = mp[val - diff] + 1;
                    ans = max(ans, mp[val]);
                }
                else mp[val] = 1;
            }
        }
        return ans;
    }
};