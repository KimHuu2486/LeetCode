class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int ans = 0;
        int n = cost.size(), i = 0;
        while (i < n) {
            ans += cost[i];
            if (i + 1 < n) {
                ans += cost[i + 1];
            }
            i += 3;
        }
        return ans;
    }
};