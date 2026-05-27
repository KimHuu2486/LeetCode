class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>lowerCase(26, -1);
        vector<int>upperCase(26, -1);
        for (int i = 0; i < word.size(); i++) {
            if (word[i] > 'Z') {
                lowerCase[word[i] - 'a'] = i;
            }
            else {
                if (upperCase[word[i] - 'A'] == -1) {
                    upperCase[word[i] - 'A'] = i;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (lowerCase[i] > -1 && lowerCase[i] < upperCase[i]) {
                ans++;
            } 
        }

        return ans;
    }
};