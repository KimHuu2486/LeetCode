class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int count = 0;
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] + nums[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] + nums[i + 1];
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) continue;

            if (left[i] == right[i])
                count += 2;
            else if (abs(left[i] - right[i]) == 1)
                count += 1;
        }

        return count;
    }
};