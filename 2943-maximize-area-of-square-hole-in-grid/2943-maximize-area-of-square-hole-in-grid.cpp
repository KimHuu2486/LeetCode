class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        
        auto maxSpan = [](vector<int>&bars) {
            int res = 1, streak = 1;
            for (int i = 1; i < bars.size(); i++) {
                if (bars[i] - bars[i - 1] == 1) {
                    streak++;
                }
                else {
                    res = max(res, streak);
                    streak = 1;
                }
            }
            res = max(res, streak);
            return res + 1;
        };

        int edge = min(maxSpan(hBars), maxSpan(vBars));
        return edge * edge;
    }
};