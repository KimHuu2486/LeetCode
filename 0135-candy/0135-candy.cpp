class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 1;
        int total = n;
        while (i < n) {
            if (ratings[i] == ratings[i - 1]) {
                i++;
                continue;
            }
            int curPeak = 0;
            while (i < n && ratings[i] > ratings[i - 1]) {
                curPeak++;
                total += curPeak;
                i++;
            }
            if (i == n)
                return total;
            int curValley = 0;
            while (i < n && ratings[i] < ratings[i - 1]) {
                curValley++;
                total += curValley;
                i++;
            }
            total -= min(curValley, curPeak);
        }
        return total;
    }
};