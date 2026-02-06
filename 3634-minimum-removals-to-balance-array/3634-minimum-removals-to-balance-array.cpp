class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int ans = 1;
        int i = 0, j = 0, n = nums.size();
        sort(nums.begin(), nums.end());

        while (j < n) {
            if (i < j) {
                long long res = 1LL * nums[i] * k;
                while (j < n && res >= nums[j]) {
                    j++;
                    ans = max(ans, j - i);
                }
                i++;
            }
            else {
                j++;
            }
        }
        return n - ans;
    }
};