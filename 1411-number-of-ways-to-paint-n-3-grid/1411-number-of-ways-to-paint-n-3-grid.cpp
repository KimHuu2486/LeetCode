class Solution {
public:
    int numOfWays(int n) {
        const long long MOD = 1e9 + 7;
        long long end_two_color = 6, end_three_color = 6;

        for (int i = 2; i <= n; i++) {
            long long prev2 = end_two_color, prev3 = end_three_color;
            end_two_color = (prev2 * 3 + prev3 * 2) % MOD;
            end_three_color = (prev2 * 2 + prev3 * 2) % MOD;
        }

        return (end_two_color + end_three_color) % MOD;
    }
};