class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k - 1 + maxPts)
            return 1.0;
        vector<double> dp(maxPts, 0.0);
        dp[0] = 1.0;
        double result = 0.0, sumProb = 1.0;
        for (int i = 1; i <= n; i++) {
            double prob = sumProb / maxPts;
            if (i < k) {
                sumProb += prob;
            } else {
                result += prob;
            }
            if (i >= maxPts) {
                sumProb -= dp[i % maxPts];
            }
            dp[i % maxPts] = prob;
        }
        return result;
    }
};