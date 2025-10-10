class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int end = n - 1;
        long long ans = INT_MIN;
        while (end >= n - k) {
            long long temp = 0;
            for (int i = end; i >= 0; i -= k) {
                temp += (long long)energy[i];
                ans = max(ans, temp);
            }
            end--;
        }
        return ans;
    }
};