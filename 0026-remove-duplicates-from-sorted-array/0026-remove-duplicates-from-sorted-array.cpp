class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count;
        if (nums.size() >= 1){
            count = 1;
        }
        else count = 0;
        for (int i = 1; i<nums.size(); i++){
            if (nums[i]!=nums[i-1]){
                nums[count] = nums[i];
                count++;
            }
        }
        return count;
    }
};