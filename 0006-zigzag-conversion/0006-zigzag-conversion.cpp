class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows>=s.size()) return s;
        string ans;
        vector<string>vec(numRows,"");
        int val = 0;
        int pos = 1;
        for (int i = 0; i<s.size(); i++){
            vec[val]+=s[i];
            if (val==0) pos = 1;
            if (val==numRows-1) pos = -1;
            val+=pos;
        }
        for (string t:vec){
            ans+=t;
        }
        return ans;
        
        
    }
};