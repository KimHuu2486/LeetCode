class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int ans = nums[0];
        while (left<=right){
            int mid = left + (right-left)/2;
            if (nums[mid]==nums[left] && nums[mid]==nums[right]) {
                ans = min(ans,nums[mid]);
                right--;
                left++;
            }
            else if (nums[mid]>=nums[left]){
                ans = min(ans, nums[left]);
                left = mid + 1;
            }
            else{
                ans = min(ans, nums[mid]);
                right = mid -1;
            }
        }
        return ans;
    }
};