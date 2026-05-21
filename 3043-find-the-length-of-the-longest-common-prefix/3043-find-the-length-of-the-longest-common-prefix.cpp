class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> prefix;
        for (const int& num: arr1) {
            string s = to_string(num);
            for (int i = 1; i <= s.size(); i++) {
                prefix.insert(s.substr(0, i));
            }
        }

        int ans = 0;
        for (const int& num: arr2) {
            string s = to_string(num);
            for (int i = ans; i <= s.size(); i++) {
                if (prefix.find(s.substr(0, i)) != prefix.end()) {
                    ans = i;
                }
            }
        }

        return ans;
    }
};