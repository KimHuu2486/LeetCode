class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int index = 0;
        for (int i =1; i<nums.size(); i++){
            if (nums[i]>nums[index]){
                index = i;
            }
        }
        int max2= 0;
        for (int i =0; i<nums.size(); i++){
            if (nums[i]>max2 && nums[i]<nums[index]){
                max2 = nums[i];
            }
        }
        if (nums[index] >= max2*2) {
            return index;
        }
        return -1; 
    }
};