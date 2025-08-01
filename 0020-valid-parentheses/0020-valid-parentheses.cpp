class Solution {
public:
    bool isValid(string s) {
        map<char, char>mp;
        mp['('] = ')';
        mp['['] = ']';
        mp['{'] = '}';
        stack<char>st;
        for (char c:s){
            if (c == ')' || c == ']' || c == '}'){
                if (!st.empty() && mp[st.top()] == c){
                    st.pop();
                }
                else return 0;
            }
            else {
                st.push(c);
            }
        }
        return st.empty();
    }
};