class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> freq(58, 0);
        for (const char& c : word) {
            freq[c - 65]++;
        }

        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0 && freq[i + 32] > 0) {
                cnt++;
            }
        }

        return cnt;
    }
};