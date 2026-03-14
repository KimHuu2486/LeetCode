class Solution {
public:
    vector<string> happyStrings;
    void generate(string &current, int n, int k) {
        if (happyStrings.size() == k) return;

        if (current.length() == n) {
            happyStrings.push_back(current);
            return;
        }

        for (char ch : {'a', 'b', 'c'}) {
            if (current.empty() || current.back() != ch) {
                current.push_back(ch);
                generate(current, n, k);
                current.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        happyStrings.clear();
        string current = "";
        generate(current, n, k);

        if (happyStrings.size() < k) return "";
        return happyStrings[k - 1];
    }
};