class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans(m * n);
        int idx = 0;
        bool isReverse = false;
        for (int k = 0; k < m; k++) {
            int i = k, j = 0, cnt = 0;
            while (i >= 0 && j < n) {
                ans[idx++] = mat[i][j];
                i--;
                j++;
                cnt++;
            }
            if (isReverse) {
                reverse(ans.begin() + idx - cnt, ans.begin() + idx);
            }
            isReverse = !isReverse;
        }
        for (int k = 1; k < n; k++) {
            int i = m - 1, j = k, cnt = 0;
            while (i >= 0 && j < n) {
                ans[idx++] = mat[i][j];
                i--;
                j++;
                cnt++;
            }
            if (isReverse) {
                reverse(ans.begin() + idx - cnt, ans.begin() + idx);
            }
            isReverse = !isReverse;
        }
        return ans;
    }
};