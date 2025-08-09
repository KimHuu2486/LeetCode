class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> ans(obstacles.size(), 1);
        vector<int> LIS;
        LIS.push_back(obstacles[0]);
        for (int i = 1; i < obstacles.size(); i++) {
            if (*LIS.rbegin() <= obstacles[i]) {
                LIS.push_back(obstacles[i]);
                ans[i] = LIS.size();
            } else {
                int idx = upper_bound(LIS.begin(), LIS.end(), obstacles[i]) - LIS.begin();
                LIS[idx] = obstacles[i];
                ans[i] = idx + 1;
            }
        }
        return ans;
    }
};