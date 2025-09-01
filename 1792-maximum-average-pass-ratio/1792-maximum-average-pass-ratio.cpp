class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>, vector<pair<double, int>>> heap;
        int n = classes.size();
        for (int i = 0; i < n; i++) {
            double cur = (double)classes[i][0] / classes[i][1];
            double next = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
            heap.push({next - cur, i});
        }
        while (extraStudents > 0) {
            auto cur = heap.top();
            heap.pop();
            classes[cur.second][0]++;
            classes[cur.second][1]++;
            double old =
                (double)classes[cur.second][0] / classes[cur.second][1];
            double next = (double)(classes[cur.second][0] + 1) /
                          (classes[cur.second][1] + 1);
            heap.push({next - old, cur.second});
            extraStudents--;
        }
        double ans = 0.0;
        for (int i = 0; i < n; i++) {
            ans += (double)classes[i][0] / classes[i][1];
        }
        return ans / n;
    }
};