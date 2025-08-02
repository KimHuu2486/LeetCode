class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return true;
        int idx = 0;
        while (idx < n - 1 && nums[idx] == nums[idx + 1])
            idx++;
        if (idx == n - 1) return true;
        bool increasing = nums[idx] < nums[idx + 1];
        for (int i = idx + 1; i < n - 1; i++) {
            if ((increasing && nums[i] > nums[i + 1]) ||
                (!increasing && nums[i] < nums[i + 1])) {
                return false;
            }
        }
        return true;
    }
};
