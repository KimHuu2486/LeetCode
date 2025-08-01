class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for(int i=0;i<n;i += 2*k){
            int end = min(i+k-1,n-1);
            reverse(s.begin()+i,s.begin()+end+1);
        }
        return s;
    }
};