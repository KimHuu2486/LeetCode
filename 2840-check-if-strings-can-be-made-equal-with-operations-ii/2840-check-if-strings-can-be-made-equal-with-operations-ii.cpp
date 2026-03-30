class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        vector<int>freqEvens1(26, 0), freqEvens2(26, 0);
        vector<int>freqOdds1(26, 0), freqOdds2(26, 0);

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                freqEvens1[s1[i] - 'a']++;
                freqEvens2[s2[i] - 'a']++;
            }
            else {
                freqOdds1[s1[i] - 'a']++;
                freqOdds2[s2[i] - 'a']++;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (freqEvens1[i] != freqEvens2[i]) return false;
            if (freqOdds1[i] != freqOdds2[i]) return false;
        }
        
        return true;
    }
};