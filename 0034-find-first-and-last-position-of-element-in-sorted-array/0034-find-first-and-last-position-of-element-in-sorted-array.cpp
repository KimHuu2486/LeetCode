class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size()==0){
            return {-1, -1};
        }
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if (nums[mid] == target){
                while(nums[high]>target){
                    high--;
                }
                while(nums[low]<target){
                    low++;
                }
                return {low, high};
            }
            else if (nums[mid]>target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return {-1, -1};
    }
};