class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cntOnes = count(nums.begin(), nums.end(), 1);
        if (cntOnes > 0)
            return n - cntOnes;

        int best = INT_MAX;

        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i + 1; j < n; j++) {
                g = std::gcd(g, nums[j]);
                if (g == 1) {
                    best = min(best, j - i + 1);
                    break;
                }
            }
        }

        if (best == INT_MAX)
            return -1;
        return (best - 1) + (n - 1);
    }
};