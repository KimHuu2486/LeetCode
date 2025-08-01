class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int count = 0;
        long long leftSum = 0;
        long long rightSum = 0;
        for (int num: nums){
            rightSum+=num;
        }
        for (int i = 0; i<nums.size() - 1;i++){
            leftSum+=(long long)nums[i];
            rightSum-=(long long)nums[i];
            if (leftSum>=rightSum) count++;
        }
        return count;
    }
};