class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy(INT_MIN), sell(0);
        for (int price: prices){
            buy = max(sell - price, buy);
            sell = max(buy + price - fee, sell);
        }
        return sell;
    }
};