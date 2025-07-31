class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i =0; i<nums.size(); i++){
            if (i>0&& nums[i] == nums[i-1]){
                continue;
            }
            for (int j = i+1; j<nums.size(); j++){
                if (j>i+1&&nums[j]==nums[j-1]){
                    continue;
                }
                int k = j+1;
                int h = nums.size()-1;
                while(k<h){
                long long sum = nums[i];
                sum+=nums[j];
                sum+=nums[k];
                sum+=nums[h];
                if (sum==target){
                    result.push_back({nums[i], nums[j], nums[k], nums[h]});
                    h--;
                    k++;
                    while(k<h && nums[k] == nums[k-1]){
                        k++;
                    }
                    while(k<h && nums[h] == nums[h+1]){
                        h--;
                    }
                }
                else if (sum>target){
                    h--;
                }
                else {
                    k++;
                }
                }
            }
            
        }
        return result;
    }
};