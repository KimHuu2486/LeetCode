class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [&](const auto& a, const auto& b) {
                 if (a[0] == b[0]) {
                     return a[1] > b[1];
                 }
                 return a[0] < b[0];
             });

        int n = intervals.size();
        int cur = 0, ans = n;
        for (int i = 1; i < n; i++) {
            if (intervals[cur][0] <= intervals[i][0] &&
                intervals[cur][1] >= intervals[i][1]) {
                ans--;
            } else
                cur = i;
        }

        return ans;
    }
};