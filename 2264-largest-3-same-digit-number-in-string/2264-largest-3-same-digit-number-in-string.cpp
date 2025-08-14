class Solution {
public:
    string largestGoodInteger(string num) {
        vector<string> vec = {"999", "888", "777", "666", "555",
                              "444", "333", "222", "111", "000"};
        for (const string& s : vec) {
            if (num.find(s) != string::npos)
                return s;
        }
        return "";
    }
};