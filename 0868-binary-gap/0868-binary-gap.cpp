class Solution {
public:
    int binaryGap(int n) {
        int prev, cur = -1, cnt = 1, ans = 0;
        while (n > 0) {
            if (n & 1) {
                prev = cur;
                cur = cnt;
                if (prev != -1) {
                    ans = max(ans, cur - prev);
                }
            }
            cnt++;
            n >>= 1;
        }
        return ans;
    }
};