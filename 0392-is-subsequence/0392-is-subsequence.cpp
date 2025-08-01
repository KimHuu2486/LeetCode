class Solution {
public:
    bool isSubsequence(string s, string t) {
        int index = 0;
        if (s.size() == 0) return 1;
        for (int i = 0; i<t.size(); i++){
            if (s[index] == t[i]) index++;
            if (index>=s.size()) return 1;
        }
        return 0;
    }
};