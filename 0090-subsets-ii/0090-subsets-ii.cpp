class Solution {
public:
    void SubSet(vector<vector<int>>&ans, vector<int>&temp, vector<int>nums, int index){
        ans.push_back(temp);
        for (int i = index; i<nums.size(); i++){
            if (i!=index && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            SubSet(ans, temp, nums, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(), nums.end());
        SubSet(ans, temp, nums, 0);
        return ans;
    }
};