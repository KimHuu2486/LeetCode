class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        long long left = 0;
        int n = prices.size();
        while (left < n) {
            long long right = left + 1;
            while (right < n && prices[right] - prices[right - 1] == -1) {
                right++;
            }
            long long m = right - left;
            ans += m * (m + 1) / 2;
            left = right;
        }
        return ans;

    }
};