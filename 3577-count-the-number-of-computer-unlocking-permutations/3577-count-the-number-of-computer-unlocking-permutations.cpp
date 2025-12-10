class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        int root = complexity[0];
        for (int i = 1; i < n; i++) {
            if (complexity[i] <= root) {
                return 0;
            }
        }
        long long ans = 1LL;
        const int MOD = 1e9 + 7;
        for (int i = n - 1; i > 1; i--) {
            ans = (ans * i) % MOD;
        }
        return ans;
    }
};