class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> buy(k + 1, INT_MIN);
        vector<int> profit(k + 1, 0);
        for (int i = 0; i < prices.size(); i++) {
            for (int j = k; j > 0; j--) {
                buy[j] = max(buy[j], profit[j - 1] - prices[i]);
                profit[j] = max(profit[j], buy[j] + prices[i]);
            }
        }
        return profit[k];
    }
};