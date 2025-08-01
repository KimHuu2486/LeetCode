class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int>prefixSum(n+1, 0);
        for (auto shift: shifts){
            int start = shift[0];
            int end = shift[1];
            int direction = (shift[2] == 1)?1:-1;
            prefixSum[start]+=direction;
            prefixSum[end+1]-=direction;
        }
        int curShift = 0;
        for (int i = 0; i<prefixSum.size(); i++){
            curShift+=prefixSum[i];
            s[i] = 'a' + ((s[i] - 'a' + curShift)%26 + 26)%26;
            
        }
        return s;
    }
};