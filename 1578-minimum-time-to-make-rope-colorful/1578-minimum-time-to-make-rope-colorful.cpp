class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int time = 0;
        for (int i = 0; i < n - 1; i++) {
            if (colors[i] == colors[i + 1]) {
                int maxTime = max(neededTime[i], neededTime[i + 1]);
                int curSumTime = neededTime[i] + neededTime[i + 1];
                int j = i + 1;
                while (j + 1 < n && colors[j] == colors[j + 1]) {
                    curSumTime += neededTime[j + 1];
                    maxTime = max(maxTime, neededTime[j + 1]);
                    j++;
                }
                i = j;
                time += curSumTime - maxTime;
            }
        }
        return time;
    }
};