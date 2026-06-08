class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> left(n), right;
        int cntPivot = 0, curLeft = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                left[curLeft] = nums[i];
                curLeft++;
            } else if (nums[i] == pivot) {
                cntPivot++;
            } else {
                right.push_back(nums[i]);
            }
        }

        for (int i = 0; i < cntPivot; i++) {
            left[curLeft] = pivot;
            curLeft++;
        }

        for (const int& r : right) {
            left[curLeft] = r;
            curLeft++;
        }

        return left;
    }
};