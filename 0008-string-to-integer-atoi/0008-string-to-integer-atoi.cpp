class Solution {
public:
    int myAtoi(string s) {
        long ans = 0;
        int n = s.length();
        int i = 0;
        while (i < n && s[i] == ' ') {
            i++;
        }
        bool isPos = 1;
        if (s[i] < '0' || s[i] > '9') {
            if (s[i] == '+')
                i++;
            else if (s[i] == '-') {
                i++;
                isPos = 0;
            } 
            else
                return ans;
        }
        while (i<n && s[i] >= '0' && s[i] <= '9') {
            ans = ans * 10 + (s[i] - '0');
            if (ans > INT_MAX && isPos == 1)
                return INT_MAX;
            else if (ans > INT_MAX && isPos == 0)
                return INT_MIN;
            i++;
        }
        if (isPos == 0)
            return -ans;
        return ans;
    }
};