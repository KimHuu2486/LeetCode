class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int Sum = (n+1)*n/2;
        int trueSum = 0;
        for (int num:nums){
            trueSum+=num;
        }
        return Sum-trueSum;
    }
};