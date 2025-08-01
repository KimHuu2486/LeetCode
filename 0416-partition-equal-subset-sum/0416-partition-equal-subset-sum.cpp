class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num:nums){
            sum+=num;
        }
        if (sum%2!=0) return 0;
        sum/=2;
        vector<bool>dp(sum+1, 0);
        dp[0] = 1;
        for (int num: nums){
            for (int i = sum; i>=num; i--){
                dp[i] = dp[i] || dp[i-num];
            }
        }
        return dp[sum];
    }
};