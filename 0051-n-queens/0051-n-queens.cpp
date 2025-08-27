class Solution {
public:
    void solve(vector<vector<string>>& ans, vector<string>& res,
               vector<int>& main, vector<int>& anti, vector<int>& col, int i,
               int n) {
        if (i == n) {
            ans.push_back(res);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (col[j] || main[i - j + n - 1] || anti[i + j])
                continue;
            res[i][j] = 'Q';
            col[j] = 1;
            main[i - j + n - 1] = 1;
            anti[i + j] = 1;
            solve(ans, res, main, anti, col, i + 1, n);
            res[i][j] = '.';
            col[j] = 0;
            main[i - j + n - 1] = 0;
            anti[i + j] = 0;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> main(2 * n - 1, 0);
        vector<int> anti(2 * n - 1, 0);
        vector<int> col(n, 0);
        vector<vector<string>> ans;
        vector<string> res(n, string(n, '.'));
        solve(ans, res, main, anti, col, 0, n);
        return ans;
    }
};