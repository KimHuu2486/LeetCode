class Solution {
public:
    void backTracking(vector<vector<int>>& ans, vector<int>& nums,
                      vector<int>& candidates, int target, int start) {
        if (target == 0) {
            ans.push_back(nums);
            return;
        }
        for (int i = start; i < candidates.size() && candidates[i] <= target; i++) {
            nums.push_back(candidates[i]);
            backTracking(ans, nums, candidates, target - candidates[i], i);
            nums.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> nums;
        backTracking(ans, nums, candidates, target, 0);
        return ans;
    }
};