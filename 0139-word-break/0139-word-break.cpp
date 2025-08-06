class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (string& word : wordDict) {
                int start = i - word.size();
                if (start >= 0 && dp[start] &&
                    s.substr(start, word.size()) == word) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};