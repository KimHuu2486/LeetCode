struct info {
    int start;
    int dur;
    int end;
};

class Solution {
public:
    long long solve(const vector<int>& aStart, const vector<int>& aDur,
              const vector<int>& bStart, const vector<int>& bDur) {
        int n = aStart.size(), m = bStart.size();
        vector<info> A(n);
        for (int i = 0; i < n; i++) {
            A[i] = {aStart[i], aDur[i], aStart[i] + aDur[i]};
        }

        sort(A.begin(), A.end(),
             [](const info& x, const info& y) { return x.start < y.start; });

        vector<int> prefMinDuration(n), suffMinEndTime(n);
        prefMinDuration[0] = A[0].dur;
        for (int i = 1; i < n; i++) {
            prefMinDuration[i] = min(prefMinDuration[i - 1], A[i].dur);
        }

        suffMinEndTime[n - 1] = A[n - 1].end;
        for (int i = n - 2; i >= 0; i--) {
            suffMinEndTime[i] = min(suffMinEndTime[i + 1], A[i].end);
        }

        long long minTime = INT_MAX;

        for (int i = 0; i < m; i++) {
            int e = bStart[i] + bDur[i];

            auto it = lower_bound(A.begin(), A.end(), e,
                                  [](const info& item, const int& val) {
                                      return item.start < val;
                                  });

            int k = distance(A.begin(), it);

            if (k > 0) {
                minTime = min(minTime, 0LL + e + prefMinDuration[k - 1]);
            }

            if (k < n) {
                minTime = min(minTime, 0LL + suffMinEndTime[k]);
            }
        }

        return minTime;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        return min(
            solve(landStartTime, landDuration, waterStartTime, waterDuration),
            solve(waterStartTime, waterDuration, landStartTime, landDuration));
    }
};