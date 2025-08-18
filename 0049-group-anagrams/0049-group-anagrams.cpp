class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans;
        for (string s : strs) {
            string x = s;
            sort(x.begin(), x.end());
            ans[x].push_back(s);
        }
        vector<vector<string>> result;
        for (auto it : ans) {
            result.push_back(it.second);
        }
        return result;
    }
};