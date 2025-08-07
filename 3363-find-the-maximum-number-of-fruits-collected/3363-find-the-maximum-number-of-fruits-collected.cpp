class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += fruits[i][i];
            fruits[i][i] = 0;
        }
        for (int pass = 1; pass <= 2; pass++) {
            if (pass == 2) {
                for (int i = 0; i < n; i++) {
                    for (int j = i + 1; j < n; j++) {
                        {
                            swap(fruits[i][j], fruits[j][i]);
                        }
                    }
                }
            }
            vector<int> prev(n, -1), cur(n, -1);
            prev[n - 1] = fruits[0][n - 1];
            for (int row = 1; row < n - 1; row++) {
                fill(cur.begin(), cur.end(), -1);
                for (int j = 0; j < n; j++) {
                    if (prev[j] < 0)
                        continue;
                    if (j > 0) {
                        cur[j - 1] =
                            max(cur[j - 1], prev[j] + fruits[row][j - 1]);
                    }
                    if (j < n - 1) {
                        cur[j + 1] =
                            max(cur[j + 1], prev[j] + fruits[row][j + 1]);
                    }
                    cur[j] = max(cur[j], prev[j] + fruits[row][j]);
                }
                swap(prev, cur);
            }
            ans += prev[n - 1];
        }
        return ans;
    }
};