class Solution {
public:
    int maxScore(string s) {
        int maxScore = 0;
        int  one = count(s.begin(), s.end(), '1');
        int zero = 0;
        for (int i = 0; i<s.size()-1; i++){
            if (s[i] == '1'){
                one--;
            }
            else{
                zero++;
            }
            maxScore = max(maxScore, one+zero);
        }
        return maxScore;
    }
};