class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        int zeroes = 0, ones = 0;
        bool cur = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                if (!cur) {
                    zeroes++;
                }
                else {
                    ans += min(zeroes, ones);
                    zeroes = 1;
                    cur = false;
                }
            }
            else {
                if (cur) {
                    ones++;
                }
                else {
                    ans += min(zeroes, ones);
                    ones = 1;
                    cur = true;
                }
            }
        }
        ans += min(zeroes, ones);
        return ans;
    }
};