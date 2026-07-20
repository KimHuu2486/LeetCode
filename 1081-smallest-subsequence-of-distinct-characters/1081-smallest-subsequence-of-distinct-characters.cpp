class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last_index(26, -1);
        for (int i = 0; i < s.length(); i++) {
            last_index[s[i] - 'a'] = i;
        }

        vector<bool> visited(26, false);
        string st = "";

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (visited[c - 'a'])
                continue;

            while (!st.empty() && st.back() > c &&
                   last_index[st.back() - 'a'] > i) {
                visited[st.back() - 'a'] = false; 
                st.pop_back();                 
            }

            st.push_back(c);
            visited[c - 'a'] = true;
        }

        return st;
    }
};