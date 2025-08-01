class Solution {
public:
    bool checkSubString(string s, unordered_map<string,int>mp, int lenword){
        for (int j = 0; j<s.size(); j+=lenword){
            string cur = s.substr(j, lenword);
            if (mp.count(cur) == 1){
                if (--mp[cur]==-1) return 0;
            }
            else return 0;
        }
        return 1;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        int lenword = words[0].size();
        int lenWindow = lenword * words.size();
        unordered_map<string,int>mp;
        for (string tem: words){
            mp[tem]++;
        }
        int i = 0;
        vector<int>ans;
        while (i+lenWindow<=s.size()){
            if(checkSubString(s.substr(i,lenWindow), mp, lenword)){
                ans.push_back(i);
            }
            i++;
        }
        return ans;
    }
};