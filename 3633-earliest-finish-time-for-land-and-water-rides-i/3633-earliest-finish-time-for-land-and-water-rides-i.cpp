struct info {
    int start;
    int dur;
    int end;
};

class Solution {
private:
    int solveOneDirection(const vector<int>& aStart, const vector<int>& aDur,
                          const vector<int>& bStart, const vector<int>& bDur) {
        int n = aStart.size();
        int m = bStart.size();

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

        int minTime = INT_MAX;

        for (int i = 0; i < m; i++) {
            int e = bStart[i] + bDur[i];

            auto it = lower_bound(
                A.begin(), A.end(), e,
                [](const info& item, int val) { return item.start < val; });
            int k = distance(A.begin(), it);

            if (k > 0) {
                minTime = min(minTime, e + prefMinDuration[k - 1]);
            }

            if (k < n) {
                minTime = min(minTime, suffMinEndTime[k]);
            }
        }

        return minTime;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int case1 = solveOneDirection(waterStartTime, waterDuration,
                                      landStartTime, landDuration);

        int case2 = solveOneDirection(landStartTime, landDuration,
                                      waterStartTime, waterDuration);

        return min(case1, case2);
    }
};