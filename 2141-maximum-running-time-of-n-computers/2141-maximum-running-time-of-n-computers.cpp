class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long totalTime = 0LL;
        for (int& b : batteries)
            totalTime += b;

        sort(batteries.begin(), batteries.end());
        for (int i = batteries.size() - 1; i >= 0; i--) {
            if (batteries[i] > totalTime / n) {
                totalTime -= batteries[i];
                n--;
            } else
                break;
        }

        return totalTime / n;
    }
};