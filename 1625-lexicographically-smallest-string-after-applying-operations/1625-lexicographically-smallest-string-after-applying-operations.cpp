class Solution {
public:
    unordered_set<string> st;
    int a, b;
    string ans;
    string add(const string& s) {
        string temp = s;
        for (int i = 1; i < s.size(); i += 2) {
            temp[i] = ((temp[i] - '0' + a) % 10) + '0';
        }
        return temp;
    }
    string rotate(const string& s) {
        string temp = s.substr(s.size() - b) + s.substr(0, s.size() - b);
        return temp;
    }
    void dfs(const string& s) {
        if (st.find(s) != st.end())
            return;
        if (s < ans)
            ans = s;
        st.insert(s);
        dfs(add(s));
        dfs(rotate(s));
    }
    string findLexSmallestString(string s, int a, int b) {
        this->a = a;
        this->b = b;
        ans = s;
        dfs(s);
        return ans;
    }
};