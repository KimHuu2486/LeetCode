class Solution {
public:
    int binarySearch(vector<int>& vec, int target) {
        int left = 0;
        int right = vec.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (vec[mid] == target)
                return mid;
            else if (vec[mid] > target) {
                right = mid - 1;
            } else
                left = mid + 1;
        }
        return left;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (*ans.rbegin() < nums[i]) {
                ans.push_back(nums[i]);
            } else if (*ans.rbegin() == nums[i])
                continue;
            else {
                int idx = binarySearch(ans, nums[i]);
                ans[idx] = nums[i];
            }
        }
        return ans.size();
    }
};