class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closet = INT_MAX/2;
        for (int i =0; i<nums.size()-2; i++){
            int j = i+1;
            int k = nums.size() - 1;
            while(j<k){
                int current = nums[i] + nums[j] + nums[k];
                if (abs(current-target)<abs(closet-target)){
                    closet = current;
                }
                if (current<target){
                    j++;
                }
                else if (current>target){
                    k--;
                }
                else {
                    return current;
                }
            }
        }
        return closet;
    }
};