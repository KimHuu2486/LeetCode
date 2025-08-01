class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>fre(26,0);
        for (char c: s){
            fre[c-'a']++;
        }
        for (char c: t){
            if (fre[c-'a']==0) return c;
            fre[c-'a']--;
        }
        return 'a';
    }
};