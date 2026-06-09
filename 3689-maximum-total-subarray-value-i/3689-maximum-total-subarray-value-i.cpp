class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long minVal = nums[0], maxVal = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            minVal = min(minVal, 0LL + nums[i]);
            maxVal = max(maxVal, 0LL + nums[i]);
        }
        return (maxVal - minVal) * k;
    }
};