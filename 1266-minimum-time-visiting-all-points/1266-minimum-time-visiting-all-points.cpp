class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;

        auto calTime = [](int x1, int y1, int x2, int y2) {
            int deltaX = abs(x1 - x2);
            int deltaY = abs(y1 - y2);
            return max(deltaX, deltaY);
        };

        int n = points.size();
        for (int i = 0; i < n - 1; i++) {
            ans += calTime(points[i][0], points[i][1], points[i + 1][0], points[i + 1][1]);
        }

        return ans;
    }
};