class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>ans;
        for (string s:strs){
            vector<int>fre(26,0);
            for (char c: s){
                fre[c-'a']++;
            }
            string key="";
            for (int i:fre){
                key+=to_string(i) + "#";
            }
            ans[key].push_back(s);
        }
        vector<vector<string>>result;
        for (auto it:ans){
            result.push_back(it.second);
        }
        return result;

    }
};