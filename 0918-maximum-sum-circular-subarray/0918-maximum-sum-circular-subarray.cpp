class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = nums[0], curMax = 0, minSum = nums[0], curMin = 0,
            total = 0;
        for (int& cur : nums) {
            curMax = max(curMax + cur, cur);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + cur, cur);
            minSum = min(curMin, minSum);
            total += cur;
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};