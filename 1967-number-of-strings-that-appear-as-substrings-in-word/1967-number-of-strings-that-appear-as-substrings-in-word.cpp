class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = word.size();
        int ans = 0;
        for (const string& s: patterns) {
            if (s.size() <= n && word.find(s) != string::npos) {
                ans++;
            }
        }
        return ans;
    }
};