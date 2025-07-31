class Solution {
public:
    void CreatSubSet(vector<vector<int>>&ans, vector<int>&subset, int index, vector<int>nums){
        if (index == nums.size()){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        CreatSubSet(ans, subset, index+1 , nums);
        subset.pop_back();
        CreatSubSet(ans, subset, index+1, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>subset;
        CreatSubSet(ans, subset, 0, nums);
        return ans;
    }
};