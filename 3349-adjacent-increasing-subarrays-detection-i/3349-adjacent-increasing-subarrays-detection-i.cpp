class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i + 2 * k <= n; ++i) {
            bool inc1 = true, inc2 = true;
            for (int j = i + 1; j < i + k; ++j)
                if (nums[j] <= nums[j - 1]) inc1 = false;
            for (int j = i + k + 1; j < i + 2 * k; ++j)
                if (nums[j] <= nums[j - 1]) inc2 = false;
            if (inc1 && inc2)
                return true;
        }
        return false;
    }
};