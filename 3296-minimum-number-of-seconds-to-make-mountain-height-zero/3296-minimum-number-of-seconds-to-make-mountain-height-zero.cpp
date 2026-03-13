class Solution {
public:
    long long getMaxHeight(long long workerTime, long long maxTime) {
        long long low = 0, high = 1e6;
        long long target = (2 * maxTime) / workerTime;
        long long res = 0;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (mid * (mid + 1) <= target) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
    bool check(int mountainHeight, const vector<int>& workerTimes,
               long long target) {
        for (int i = 0; i < workerTimes.size(); i++) {
            mountainHeight -= getMaxHeight(workerTimes[i], target);
            if (mountainHeight <= 0)
                return true;
        }
        return mountainHeight <= 0;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int minT = workerTimes[0];
        for(int t : workerTimes) minT = min(minT, t);
        
        long long low = 0;
        long long h = mountainHeight;
        long long high = (long long)minT * h * (h + 1) / 2;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(mountainHeight, workerTimes, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};