class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        int totalRequired = 1 << k;
        
        if (n < totalRequired) return false; 

        unordered_set<string_view> st;

        for (int i = 0; i <= n - k; ++i) {
            st.insert(string_view(s).substr(i, k));
            
            if (st.size() == totalRequired) {
                return true;
            }
        }

        return st.size() == totalRequired;
    }
};