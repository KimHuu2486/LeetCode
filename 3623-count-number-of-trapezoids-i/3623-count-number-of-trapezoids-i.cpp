class Solution {
public:
    const int MOD = 1e9 + 7;
    long long C2(long long n) {
        if (n < 2) return 0;
        return (n * (n - 1) / 2) % MOD;
    }
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        const int MOD = 1e9 + 7;
        unordered_map<int, int> mp;
        for (auto& point: points) {
            mp[point[1]]++;
        }
        long long ans = 0LL;
        long long prefix = 0;

        for (auto &kv : mp) {
            int cnt = kv.second;
            if (cnt < 2) continue;

            long long ai = C2(cnt);

            ans = (ans + ai * prefix) % MOD;

            prefix = (prefix + ai) % MOD;
        }

        return ans;
    }
};