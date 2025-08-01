class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for (int i =0 ;i<n/2; i++){
            int j = n-1-i;
            swap(s[i], s[j]);
        }
    }
};