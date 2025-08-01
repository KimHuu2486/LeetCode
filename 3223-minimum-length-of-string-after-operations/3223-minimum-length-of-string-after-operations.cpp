class Solution {
public:
    int minimumLength(string s) {
        int fre[26] = {};
        for (char c:s){
            fre[c-'a']++;
        }
        int count = 0;
        for (int i = 0; i<26; i++){
            if (fre[i]!=0){
                if (fre[i]%2==0) count+=2;
                else count++;
            }
        }
        return count;
    }
};