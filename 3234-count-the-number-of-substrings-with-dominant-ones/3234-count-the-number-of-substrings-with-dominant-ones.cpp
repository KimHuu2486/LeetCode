class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> zero;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') zero.push_back(i);
        }
        int m = zero.size();

        long long res = 0;

        for (int left = 0; left < n; ++left) {
            int posL = lower_bound(zero.begin(), zero.end(), left) - zero.begin();

            int firstZeroPos = (posL < m ? zero[posL] : n);
            res += firstZeroPos - left;

            if (posL == m) continue;

            for (int k = 1; 1LL * k * k <= n; ++k) {
                int idR = posL + k - 1;
                if (idR >= m) break;

                int last0 = zero[idR];
                int nextZero = (idR + 1 < m ? zero[idR + 1] : n);

                long long minRightNeeded = 1LL * left + 1LL * k * k + k - 1;
                long long minRight = max<long long>(last0, minRightNeeded);

                if (minRight >= nextZero) continue;

                res += nextZero - minRight;
            }
        }

        return (int)res;
    }
};
