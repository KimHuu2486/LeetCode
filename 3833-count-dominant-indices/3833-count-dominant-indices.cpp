class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        double sum = 0.0f + *nums.rbegin();
        double n = 1.0f;
        int cnt = 0;
        for (int i = nums.size() - 2; i >= 0; i--) {
            double temp = sum / n;
            if (0.0f + nums[i] > temp) {
                cnt++;
            }
            sum += nums[i];
            n++;
        }
        return cnt;
    }
};