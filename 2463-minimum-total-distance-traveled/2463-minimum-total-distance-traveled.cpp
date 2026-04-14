class Solution {
public:
    vector<vector<long long>>dp;
    int n, m;

    long long solve(int i, int j, vector<int>& robot, vector<vector<int>>& factory) {
        if (i == n) return 0;
        if (j == m) return 1e15;
        if (dp[i][j] != -1) return dp[i][j];

        long long res = solve(i, j + 1, robot, factory);

        int pos = factory[j][0], cap = factory[j][1];
        long long cost = 0LL;

        for (int k = 0; k < cap && i + k < n; k++) {
            cost += abs(robot[i + k] - pos);
            res = min(res, cost + solve(i + k + 1, j + 1, robot, factory));
        }

        return dp[i][j] = res;
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        n = robot.size();
        m = factory.size();
        dp.assign(n, vector<long long>(m, -1));

        return solve(0, 0, robot, factory);
    }
};