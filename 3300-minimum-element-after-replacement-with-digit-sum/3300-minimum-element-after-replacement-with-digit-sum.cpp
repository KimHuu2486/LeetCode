class Solution {
public:
    int minElement(vector<int>& nums) {
        auto sumDigit = [](int& a) {
            int ans = 0;
            while (a > 0) {
                ans += a % 10;
                a /= 10;
            }
            return ans;
        };

        int ans = INT_MAX;
        for (int& num: nums) {
            ans = min(ans, sumDigit(num));
        }
        return ans;
    }
};