class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int right = nums.size() - 1, mid = right - 1, left = mid - 1;
        while (left >= 0) {
            if (nums[right] < nums[mid] + nums[left])
                return nums[right] + nums[mid] + nums[left];
            right--;
            mid--;
            left--;
        }
        return 0;
    }
};