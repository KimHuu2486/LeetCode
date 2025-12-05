class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n + 1, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            prefix[i + 1] += prefix[i] + nums[i];
            if (prefix[i + 1] % 2 == 0) {
                cnt++;
            }
        }

        if (prefix[n] % 2 != 0) return 0;
        return n - 1;
    }
};