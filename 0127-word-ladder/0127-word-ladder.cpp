class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (cur.first == endWord)
                return cur.second;
            for (int i = 0; i < beginWord.size(); i++) {
                char original = cur.first[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    cur.first[i] = c;
                    if (st.find(cur.first) != st.end()) {
                        st.erase(cur.first);
                        q.push({cur.first, cur.second + 1});
                    }
                }
                cur.first[i] = original;
            }
        }
        return 0;
    }
};