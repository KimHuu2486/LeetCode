class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance,
                 vector<int>& walls) {
        int n = robots.size();

        vector<pair<int, int>> sortedRobots(n);
        for (int i = 0; i < n; i++) {
            sortedRobots[i] = {robots[i], distance[i]};
        }
        sort(sortedRobots.begin(), sortedRobots.end());
        sort(walls.begin(), walls.end());

        sortedRobots.push_back({2e9, 0});

        auto countWalls = [&](int l, int r) {
            if (l > r)
                return 0;
            auto it1 = upper_bound(walls.begin(), walls.end(), r);
            auto it2 = lower_bound(walls.begin(), walls.end(), l);
            return int(it1 - it2);
        };

        // dp[i][0] = max walls up to robot i, with robot i sweeping left
        // dp[i][1] = max walls up to robot i, with robot i sweeping right
        vector<array<int, 2>> dp(n);

        int firstPos = sortedRobots[0].first;
        int firstDist = sortedRobots[0].second;
        int nextPos = sortedRobots[1].first;

        dp[0][0] = countWalls(firstPos - firstDist, firstPos);
        dp[0][1] = countWalls(firstPos, min(nextPos - 1, firstPos + firstDist));

        for (int i = 1; i < n; i++) {
            int currPos = sortedRobots[i].first;
            int currDist = sortedRobots[i].second;
            int prevPos = sortedRobots[i - 1].first;
            int prevDist = sortedRobots[i - 1].second;
            int nxtPos = sortedRobots[i + 1].first;

            int rightSweepBound = min(nxtPos - 1, currPos + currDist);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0]) +
                       countWalls(currPos, rightSweepBound);

            int leftBound = max(currPos - currDist, prevPos + 1);
            int wallsInLeftSweep = countWalls(leftBound, currPos);

            int prevLeftOption = dp[i - 1][0] + wallsInLeftSweep;

            int overlapRightBound = min(prevPos + prevDist, currPos - 1);
            int overlapWalls = countWalls(leftBound, overlapRightBound);
            int prevRightOption =
                dp[i - 1][1] + wallsInLeftSweep - overlapWalls;

            dp[i][0] = max(prevLeftOption, prevRightOption);
        }

        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};