class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int n = nums.size();
        int mid = (n + 1) / 2;
        int right = n;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                nums[i] = sorted[--mid];
            } else {
                nums[i] = sorted[--right];
            }
        }
    }
};