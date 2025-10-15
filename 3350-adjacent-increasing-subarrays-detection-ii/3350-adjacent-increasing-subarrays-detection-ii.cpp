class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        vector<int> inc;
        while (i < n) {
            int j = i + 1;
            while (j < n && nums[j] > nums[j - 1]) {
                j++;
            }
            inc.push_back(j - i);
            i = j;
        }
        int ans = inc[0] / 2;
        for (i = 1; i < inc.size(); i++) {
            ans = max(ans, max(min(inc[i], inc[i - 1]), inc[i] / 2));
        }
        return ans;
    }
};