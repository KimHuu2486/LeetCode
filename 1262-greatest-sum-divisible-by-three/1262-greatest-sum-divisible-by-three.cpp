class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        const int INF = 1e9;
        int min1_r1 = INF, min2_r1 = INF;
        int min1_r2 = INF, min2_r2 = INF;

        for (int x : nums) {
            sum += x;
            if (x % 3 == 1) {
                if (x < min1_r1) {
                    min2_r1 = min1_r1;
                    min1_r1 = x;
                } else if (x < min2_r1) {
                    min2_r1 = x;
                }
            } else if (x % 3 == 2) {
                if (x < min1_r2) {
                    min2_r2 = min1_r2;
                    min1_r2 = x;
                } else if (x < min2_r2) {
                    min2_r2 = x;
                }
            }
        }

        if (sum % 3 == 0)
            return sum;

        int removeCost = INF;
        if (sum % 3 == 1) {
            removeCost = min(removeCost, min1_r1);
            if (min1_r2 < INF && min2_r2 < INF)
                removeCost = min(removeCost, min1_r2 + min2_r2);
        } else {
            removeCost = min(removeCost, min1_r2);
            if (min1_r1 < INF && min2_r1 < INF)
                removeCost = min(removeCost, min1_r1 + min2_r1);
        }

        if (removeCost >= INF)
            return 0;
        return sum - removeCost;
    }
};