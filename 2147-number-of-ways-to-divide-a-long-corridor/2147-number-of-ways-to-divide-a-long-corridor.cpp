class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();
        vector<long long>division;
        const int MOD = 1e9 + 7;
        int prev = -1;
        int cnt = 0;
        bool isHasdivision = false;
        for (int i = 0; i < n; i++) {
            if (corridor[i] == 'S') {
                if (cnt == 0 && prev != -1) {
                    division.push_back(i - prev + 1);
                }
                cnt++;
                if (cnt == 2) {
                    isHasdivision = true;
                    prev = i + 1;
                    cnt = 0;
                }
            }
        }
        if (cnt != 0 || !isHasdivision) return 0;
        long long ans = 1;
        for (long long num: division) {
            ans = (ans * num) % MOD;
        }
        return ans;

    }
};