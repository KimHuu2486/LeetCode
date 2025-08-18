class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        int cnt = 1;
        int pos = points[0][1];
        for (auto& cur : points) {
            if (cur[0] > pos) {
                cnt++;
                pos = cur[1];
            }
        }
        return cnt;
    }
};