class Solution {
public:
    void generate(vector<string>&ans, string temp, int open ,int close, int n){
        if (temp.length() == 2 * n) {
            ans.push_back(temp);
            return;
        }

        if (open < n) {
            temp.push_back('(');  
            generate(ans, temp, open + 1, close, n);  
            temp.pop_back();  
        }

        if (close < open) {
            temp.push_back(')');  
            generate(ans, temp, open, close + 1, n);  
            temp.pop_back();  
        }
    }
    vector<string> generateParenthesis(int n) {
        string res;
        vector<string>ans;
        generate(ans, res, 0, 0, n);
        return ans;
    }
};