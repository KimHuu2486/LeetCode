class Solution {
const long long MOD = 1e9 + 7;
public:
    int numSub(string s) {
long long ans = 0;
        long long cnt = 0;

        for (char c : s) {
            if (c == '1') {
                cnt++;
            } else {
                ans = (ans + cnt * (cnt + 1) / 2) % MOD;
                cnt = 0;
            }
        }

        if (cnt > 0) {
            ans = (ans + cnt * (cnt + 1) / 2) % MOD;
        }

        return ans;
    }
};