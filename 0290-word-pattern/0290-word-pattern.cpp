class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        vector<string> words;
        string word;
        while (ss >> word) {
            words.push_back(word);
        }

        if (pattern.size() != words.size()) return false;

        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];

            if (mp1.count(c) && mp1[c] != w) return false;
            if (mp2.count(w) && mp2[w] != c) return false;

            mp1[c] = w;
            mp2[w] = c;
        }

        return true;
    }
};