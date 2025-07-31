class Solution {
public:
    void backtrack(int index, const string digits, string path, vector<string>&ans, 
                    map<char,string>mp){
        if (index == digits.size()){
            ans.push_back(path);
            return;
        }
        string possible_letter = mp[digits[index]];
        for (char letter : possible_letter){
            backtrack(index+1, digits, path+letter, ans, mp);
        }
    }
    vector<string> letterCombinations(string digits) {
        map<char, string> mp = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

        if (digits.empty()) {
            return {};
        }
        vector<string>ans;
        backtrack(0, digits, "", ans, mp);
        return ans;
    }
    
};