class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;
        int prev(1), prevPrev(1);
        for (int i = 1; i < s.size(); i++) {
            int cur = 0;
            if (s[i] != '0')
                cur += prev;
            int twoDigit = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                cur += prevPrev;
            }
            prevPrev = prev;
            prev = cur;
        }
        return prev;
    }
};