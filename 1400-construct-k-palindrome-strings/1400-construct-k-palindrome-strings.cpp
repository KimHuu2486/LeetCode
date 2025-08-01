class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k>s.size()) return 0;
        int fre[26]={};
        for (char c:s){
            fre[c-'a']++;
        }
        int pos = 0;
        for (int num:fre){
            if (num%2!=0){
                pos++;
                if (pos>k) return 0;
            }
        }
        return 1;
    }
};