class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int count = 3;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums[n-1];
        for (int i = n-2;i>=0 && count>1; i--){
            if (ans!=nums[i]) {
                ans = nums[i];
                count--;
            }
        }
        if (count>1) return nums[n-1];
        return ans;
    }
};