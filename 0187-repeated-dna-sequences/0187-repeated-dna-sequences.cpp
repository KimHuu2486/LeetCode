class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size()<=10) return {};
        vector<string>ans;
        unordered_map<string,int>mp;
        for (int i = 0; i<=s.size()-10; i++){
            mp[s.substr(i,10)]++;
        }
        for (auto i : mp){
            if (i.second>1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};