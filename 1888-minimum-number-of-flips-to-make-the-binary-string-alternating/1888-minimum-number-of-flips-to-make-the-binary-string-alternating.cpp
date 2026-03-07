class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string target1 = "", target2 = "";
        for (int i = 0; i < 2 * n; i++) {
            target1 += (i % 2 == 0 ? '0' : '1');
            target2 += (i % 2 == 0 ? '1' : '0');
        }
        
        string s2 = s + s;
        int diff1 = 0, diff2 = 0;
        int ans = INT_MAX;
        
        for (int i = 0; i < 2 * n; i++) {
            if (s2[i] != target1[i]) diff1++;
            if (s2[i] != target2[i]) diff2++;
            
            if (i >= n) {
                if (s2[i - n] != target1[i - n]) diff1--;
                if (s2[i - n] != target2[i - n]) diff2--;
            }
            
            if (i >= n - 1) {
                ans = min({ans, diff1, diff2});
            }
        }
        return ans;
    }
};