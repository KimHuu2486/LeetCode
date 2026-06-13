class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        string s(n, ' ');

        for (int i = 0; i < n; i++) {
            int sum = 0;

            for (int j = 0; j < words[i].size(); j++) {
                int idx = words[i][j] - 'a';
                sum += weights[idx];
            }

            s[i] = 'a' + (25 - sum % 26);
        }

        return s;
    }
};