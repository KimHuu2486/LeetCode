class Solution {
public:
    int minimumDeletions(string s) {
        int prevb = 0, nexta = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') {
                nexta++;
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') {
                nexta--;
                ans = min(ans, nexta + prevb);
            }
            else {
                ans = min(ans, nexta + prevb);
                prevb++;
            }
        }

        return ans;
    }
};