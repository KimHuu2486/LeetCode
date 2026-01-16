class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const long long MOD = 1e9 + 7;

        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<long long> hDiff;
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                hDiff.insert(hFences[j] - hFences[i]);
            }
        }

        long long ans = 0LL;
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                long long dis = vFences[j] - vFences[i];
                if (hDiff.count(dis)) {
                    ans = max(ans, dis);
                }
            }
        }

        return ans == 0 ? -1 : (ans * ans) % MOD;
    }
};