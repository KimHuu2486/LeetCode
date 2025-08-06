class Solution {
public:
    void backTrack(vector<string>& ans, string& s, unordered_set<string>& Word,
                   int start, string sentences) {
        if (start == s.size()) {
            ans.push_back(sentences.substr(1));
            return;
        }
        for (int end = start + 1; end <= s.size(); end++) {
            string temp = s.substr(start, end - start);
            if (Word.count(temp)) {
                backTrack(ans, s, Word, end, sentences + " " + temp);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        unordered_set<string> Word(wordDict.begin(), wordDict.end());
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && Word.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        if (!dp[n])
            return {};
        vector<string> ans;
        backTrack(ans, s, Word, 0, "");
        return ans;
    }
};