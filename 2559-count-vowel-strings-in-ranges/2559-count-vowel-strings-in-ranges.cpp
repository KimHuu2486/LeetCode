class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int  n = words.size();
        vector<int>ans;
        vector<int>status(n+1, 0);
        for (int i = 0 ; i<words.size(); i++){
            if (isVowel(words[i][0]) && isVowel(words[i].back())){
                status[i+1] = status[i] + 1;
            }
            else status[i+1] = status[i];
        }
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            ans.push_back(status[r + 1] - status[l]);
        }
        return ans;
    }
};