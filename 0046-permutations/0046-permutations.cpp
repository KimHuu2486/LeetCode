class Solution {
public:
    void backtracking(vector<vector<int>>&ans, vector<int>&nums){
        int i = nums.size()-2;
        while(i>=0&& nums[i]>nums[i+1]){
            i--;
        }
        if (i<0){
            return;
        }
        int j = nums.size()-1;
        while(nums[i]>nums[j]){
            j--;
        }
        swap(nums[i], nums[j]);
        sort(nums.begin()+i+1, nums.end());
        ans.push_back(nums);
        backtracking(ans, nums);
    }
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        ans.push_back(nums);
        backtracking(ans, nums);
        return ans;
    }
};