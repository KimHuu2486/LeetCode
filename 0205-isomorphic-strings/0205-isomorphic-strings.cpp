class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> mp(256, -1);
        vector<bool> visited(256, false);
        for (int i = 0; i < s.size(); i++) {
            if (mp[s[i]] == -1) {
                if (visited[t[i]])
                    return false;
                mp[s[i]] = t[i];
                visited[t[i]] = true;
            } else {
                if (mp[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
};