class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for (char c : t){
            mp[c]++;
        }
        int n = s.size();
        int i = 0, j= 0, cnt = t.size();
        int minLen = INT_MAX, start = 0;
        while (j<n){
            if (mp[s[j]]>0) cnt--;
            mp[s[j]]--;
            j++;
            while (cnt==0){
                if (j-i<minLen){
                    minLen = j -i;
                    start = i;
                }
                if (mp.count(s[i])){
                    mp[s[i]]++;
                    if (mp[s[i]]>0){
                        cnt++;
                    }
                }
                i++;
            }
        }
        return minLen == INT_MAX?"":s.substr(start, minLen);
    }
};