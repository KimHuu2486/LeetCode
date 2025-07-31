class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int mx =*max_element(nums.begin(), nums.end());
        vector<int>freq(mx+1, 0);
        for (int& i: nums) freq[i]++;
        int n = nums.size();
        vector<vector<int>>ans(n/3, vector<int>(3));
        int idx = 1;
        for (int i = 0; i<n/3; i++){
            for (int j = 0; j< 3; j++){
                while (idx <=mx && freq[idx] == 0) idx++;
                ans[i][j] = idx;
                freq[idx]--;
            }
            if (ans[i][2] - ans[i][0] > k) return {};
        }
        return ans;
    }
};