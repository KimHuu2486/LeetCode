class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        for (int k = 2; k<n; k++){
            int i = 0, j = k-1;
            while (i<j){
                if (nums[j] + nums[i] >nums[k]){
                    ans+=j-i;
                    j--;
                }
                else i++;
            }
        }
        return ans;
    }
};