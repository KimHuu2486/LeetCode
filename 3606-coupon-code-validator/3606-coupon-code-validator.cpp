class Solution {
public:
    bool isCheckCode(const string& code) {
        if (code == "") return false;
        for (const char& c : code) {
            if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') ||
                ('0' <= c && c <= '9') || c == '_') {
                continue;
            }
            return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        unordered_map<string, int> mp({{"electronics", 0},
                                       {"grocery", 1},
                                       {"pharmacy", 2},
                                       {"restaurant", 3}});
        vector<pair<int, string>> raw_ans;
        int n = code.size();

        for (int i = 0; i < n; i++) {
            if (!isActive[i] || mp.find(businessLine[i]) == mp.end() ||
                !isCheckCode(code[i]))
                continue;
            raw_ans.push_back({mp[businessLine[i]], code[i]});
        }

        sort(raw_ans.begin(), raw_ans.end());

        vector<string> ans(raw_ans.size());
        for (int i = 0; i < raw_ans.size(); i++) {
            ans[i] = raw_ans[i].second;
        }
        return ans;
    }
};