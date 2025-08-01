class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int count = 0;
        unordered_set<char> st;
        for (int i = 0; i < n - 2; i++) {
            if (st.count(s[i]) == 0) {
                for (int j = n - 1; j>i+1; j--) {
                    if (s[i] == s[j]) {
                        unordered_set<char>temp;
                        for (int k = i+1; k<j; k++){
                            if (temp.count(s[k]) == 0){
                                temp.insert(s[k]);
                                count++;
                            }
                        }
                        st.insert(s[i]);
                        break;
                    }
                }
            }
        }
        return count;
    }
};