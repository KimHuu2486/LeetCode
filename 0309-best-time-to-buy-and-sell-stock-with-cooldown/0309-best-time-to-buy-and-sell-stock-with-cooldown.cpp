class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy(INT_MIN), prevBuy, sell(0), prevSell(0);
        for (int price : prices) {
            prevBuy = buy;
            buy = max(prevSell - price, buy);
            prevSell = sell;
            sell = max(prevBuy + price, sell);
        }
        return sell;
    }
};