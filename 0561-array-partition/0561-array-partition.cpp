class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end() ) ;
        int sum = 0;
        int n = nums.size();
        for ( int i = 1; i < n; i += 2 ) {
            sum += nums[i - 1];
        }
        return sum;
    }
};