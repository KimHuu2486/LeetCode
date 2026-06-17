class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        long long len = 0LL;

        for (const char& c : s) {
            if (c == '*') {
                len = max(len - 1, 0LL);
            } else if (c == '#') {
                len *= 2;
            } else if (c != '%') {
                len++;
            }
        }

        if (k >= len)
            return '.';

        for (int i = n - 1;; i--) {
            if (s[i] == '*') {
                len++;
            } else if (s[i] == '#') {
                if (k >= len / 2) {
                    k -= len / 2;
                }
                len /= 2;
            } else if (s[i] == '%') {
                k = len - 1 - k;
            } else {
                if (len == k + 1) {
                    return s[i];
                }
                len--;
            }
        }
        
        return '.';
    }
};