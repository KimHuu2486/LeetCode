class Solution {
public:
    int cal(int a, int b) {
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }
    int minimumDistance(string word) {
        // p : Ngón tay vừa gõ xong, dp: ngón tay còn lại
        vector<int>dp(26), ndp(26);

        for (int i = 1; i < word.size(); i++) {
            int p = word[i - 1] - 'A', t = word[i] - 'A';
            for (int j = 0; j < 26; j++) {
                ndp[j] = dp[j]  + cal(p, t);
            }
            for (int j = 0; j < 26; j++) {
                ndp[p] = min(ndp[p], dp[j] + cal(j, t));
            }
            dp = ndp;
        }

        return *min_element(dp.begin(), dp.end());


    }
};