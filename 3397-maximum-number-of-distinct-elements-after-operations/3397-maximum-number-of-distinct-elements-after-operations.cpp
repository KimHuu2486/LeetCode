class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 1;
        nums[0] -= k;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - k > nums[i - 1]) {
                nums[i] -= k;
                cnt++;
            } else if (nums[i] + k <= nums[i - 1]) {
                nums[i] = nums[i - 1];
            } else {
                nums[i] = nums[i - 1] + 1;
                cnt++;
            }
        }
        return cnt;
    }
};