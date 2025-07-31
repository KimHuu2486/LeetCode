class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i<nums.size(); i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int j = i+1;
            int k = nums.size() - 1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if (sum>0){
                    k--;
                }
                if (sum<0){
                    j++;
                }
                if (sum==0){
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while(j<k&& nums[j]==nums[j-1]){
                        j++;
                    }
                }
            }
        }
        return result;      
    }
};