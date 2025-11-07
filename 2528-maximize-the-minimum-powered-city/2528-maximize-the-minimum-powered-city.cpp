class Solution {
public:
    bool check(vector<int> stations, int r, int additionalStation,
               long minPower) {
        int n = stations.size();
        long power = accumulate(stations.begin(), stations.begin() + r, 0LL);

        for (int i = 0; i < n; i++) {
            if (i + r < n) {
                power += stations[i + r];
            }
            if (power < minPower) {
                long requirePower = minPower - power;
                if (requirePower > additionalStation)
                    return false;
                stations[min(n - 1, i + r)] += requirePower;
                additionalStation -= requirePower;
                power += requirePower;
            }
            if (i - r >= 0) {
                power -= stations[i - r];
            }
        }
        return true;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        long left = *min_element(stations.begin(), stations.end());
        long right = accumulate(stations.begin(), stations.end(), 0LL) + k + 1;
        while (left < right) {
            long mid = left + (right - left) / 2;
            if (check(stations, r, k, mid)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left - 1;
    }
};