class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        unordered_map<string, string>mp;
        for (const string& s: words){
            string temp = s;
            sort(temp.begin(), temp.end());
            mp[s] = temp;
        }
        for (int i = 0; i < words.size(); i++) {
            ans.push_back(words[i]);
            while (i + 1 < words.size() && mp[words[i]] == mp[words[i + 1]]) {
                i++;
            }
        }
        return ans;
    }
};