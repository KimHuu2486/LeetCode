class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int r = sum % k;
        int cnt = 0;
        int idx = 0;
        while (r) {
            int dif = min(nums[idx], r);
            r -= dif;
            cnt += dif;
            idx++;
        }
        return cnt;
    }
};