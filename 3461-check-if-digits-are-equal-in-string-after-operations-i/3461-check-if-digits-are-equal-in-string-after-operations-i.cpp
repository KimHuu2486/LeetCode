class Solution {
public:
    bool hasSameDigits(string s) {
        for (int i = 0; i<s.size() - 2; i++) {
            for (int j = 0; j  < s.size() - 1 - i; j++) {
                s[j] = ((s[j] - '0') + (s[j+1] - '0') ) % 10 + '0';
            }
        }
        return s[0] == s[1];
    }
};