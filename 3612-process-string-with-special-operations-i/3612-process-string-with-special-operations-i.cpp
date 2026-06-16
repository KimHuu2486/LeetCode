class Solution {
public:
    string processStr(string s) {
        string result = "";
        for (const char& c: s) {
            if (c == '*') {
                if (result.size() > 0) {
                    result.pop_back();
                }
            }
            else if (c == '#') {
                result = result.append(result);
            }
            else if (c == '%') {
                reverse(result.begin(), result.end());
            }
            else {
                result.push_back(c);
            }
        }
        return result;
    }
};