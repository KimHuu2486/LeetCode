class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        long long prev = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            cur = prev + strategy[i] * prices[i];
            prev = cur;
        }

        long long ans = cur;

        int left = 0, right = k/2;
        while (left < right) {
            if (strategy[left] == -1) {
                cur += prices[left];
            }
            else if (strategy[left] == 1) {
                cur -= prices[left];
            }
            left++;
        }
        while (right < k) {
            if (strategy[right] == -1) {
                cur += 2 * prices[right];
            }
            else if (strategy[right] == 0) {
                cur += prices[right];
            }
            right++;
        }
        ans = max(ans, cur);

        int mid = left;
        left = right - k;
        while (right < n) {
            cur += strategy[left] * prices[left];
            cur -= prices[mid];
            if (strategy[right] == -1) {
                cur += 2 * prices[right];
            }
            else if (strategy[right] == 0) {
                cur += prices[right];
            }
            ans = max(ans, cur);
            left++; mid++; right++;
        }
        return ans;
    }
};