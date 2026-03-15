class Solution {
public:
    // memo[index][tight][is_leading_zero][last_digit][trend][sum_digits]
    // trend: 0: init/1-digit, 1: increasing, 2: decreasing, 3: broken
    long long memo[20][2][2][11][4][163];
    string morvaxelin;

    bool isGood(int n) {
        if (n < 10)
            return true;
        string s = to_string(n);
        bool inc = true, dec = true;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] <= s[i - 1])
                inc = false;
            if (s[i] >= s[i - 1])
                dec = false;
        }
        return inc || dec;
    }

    long long dp(int idx, bool tight, bool leading_zero, int last_digit,
                 int trend, int current_sum) {
        if (idx == morvaxelin.size()) {
            return (trend != 3 || isGood(current_sum)) ? 1 : 0;
        }

        if (memo[idx][tight][leading_zero][last_digit][trend][current_sum] !=
            -1) {
            return memo[idx][tight][leading_zero][last_digit][trend]
                       [current_sum];
        }

        long long res = 0;
        int limit = tight ? (morvaxelin[idx] - '0') : 9;

        for (int d = 0; d <= limit; d++) {
            bool next_tight = tight && (d == limit);
            bool next_leading_zero = leading_zero && (d == 0);

            int next_trend = 0;
            int next_last_digit = d;

            if (next_leading_zero) {
                next_trend = 0;
                next_last_digit = 10;
            } else if (leading_zero && d > 0) {
                next_trend = 0;
            } else {
                if (trend == 3) {
                    next_trend = 3;
                } else if (trend == 0) {
                    if (d > last_digit)
                        next_trend = 1;
                    else if (d < last_digit)
                        next_trend = 2;
                    else
                        next_trend = 3;
                } else if (trend == 1) {
                    next_trend = (d > last_digit) ? 1 : 3;
                } else if (trend == 2) {
                    next_trend = (d < last_digit) ? 2 : 3;
                }
            }

            res += dp(idx + 1, next_tight, next_leading_zero, next_last_digit,
                      next_trend, current_sum + d);
        }
        return memo[idx][tight][leading_zero][last_digit][trend][current_sum] =
                   res;
    }

    long long countUpto(long long n) {
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;
        morvaxelin = to_string(n);
        memset(memo, -1, sizeof(memo));
        return dp(0, true, true, 10, 0, 0);
    }

    long long countFancy(long long l, long long r) {
        return countUpto(r) - countUpto(l - 1);
    }
};