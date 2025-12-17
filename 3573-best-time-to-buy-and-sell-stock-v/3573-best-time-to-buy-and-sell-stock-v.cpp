class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();

        // flat: trạng thái không giữ cổ phiếu
        vector<long long> flat(k + 1, 0);
        
        // longPos: trạng thái đang Long (giữ cổ phiếu)
        // shortPos: trạng thái đang Short (đã bán khống)
        vector<long long> longPos(k + 1, LLONG_MIN / 2);
        vector<long long> shortPos(k + 1, LLONG_MIN / 2);

        for (int price : prices) {
            vector<long long> prev_flat = flat;

            for (int j = 1; j <= k; ++j) {
                longPos[j] = max(longPos[j], prev_flat[j-1] - price);
                shortPos[j] = max(shortPos[j], prev_flat[j-1] + price);
                flat[j] = max(flat[j], longPos[j] + price);
                flat[j] = max(flat[j], shortPos[j] - price);
            }
        }

        return flat[k];
    }
};