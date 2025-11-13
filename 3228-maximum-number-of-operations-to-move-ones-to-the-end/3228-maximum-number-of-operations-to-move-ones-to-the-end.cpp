class Solution {
public:
    int maxOperations(string s) {
        int cntOnes = 0;
        int ans = 0;
        s.push_back('1');
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '1') {
                cntOnes++;
            }
            if (s[i] == '0' &&  s[i+1] == '1') {
                ans += cntOnes;
            } 
        }
        return ans;
    }
};