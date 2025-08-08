class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        std::sort(envelopes.begin(), envelopes.end(),
                  [](const std::vector<int>& a, const std::vector<int>& b) {
                      return (a[0] != b[0]) ? (a[0] < b[0]) : (a[1] > b[1]);
                  });
        vector<int> lis;
        for (auto& env : envelopes) {
            int h = env[1];
            auto it = lower_bound(lis.begin(), lis.end(), h);
            if (it == lis.end()) {
                lis.push_back(h);
            } else {
                *it = h;
            }
        }
        return lis.size();
    }
};