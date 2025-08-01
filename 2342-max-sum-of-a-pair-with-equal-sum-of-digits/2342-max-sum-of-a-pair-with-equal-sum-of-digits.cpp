class Solution {
public:
    int SumDigit(int n){
        int sum = 0;
        while (n!=0){
            sum += n%10;
            n /=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        vector<int>sameDigit(82, -1);
        for (int i = 0; i<nums.size(); i++){
            int sum = SumDigit(nums[i]);
            if (sameDigit[sum]!=-1){
                ans = max(ans, sameDigit[sum] + nums[i]);
                sameDigit[sum] = max(sameDigit[sum], nums[i]);
            }
            else sameDigit[sum] = nums[i];
        }
        return ans;
    }
};