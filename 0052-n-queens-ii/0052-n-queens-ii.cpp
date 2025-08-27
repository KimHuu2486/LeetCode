class Solution {
public:
    void solve(int& count, vector<bool>& col, vector<bool>& d1,
               vector<bool>& d2, int i, int n) {
        if (i == n) {
            count++;
            return;
        }
        for (int j = 0; j < n; j++) {
            if (col[j] || d1[i - j + n - 1] || d2[i + j])
                continue;
            col[j] = true;
            d1[i - j + n - 1] = true;
            d2[i + j] = true;
            solve(count, col, d1, d2, i + 1, n);
            col[j] = false;
            d1[i - j + n - 1] = false;
            d2[i + j] = false;
        }
    }
    int totalNQueens(int n) {
        int count = 0;
        vector<bool> col(n, false);
        vector<bool> d1(2 * n - 1, false);
        vector<bool> d2(2 * n - 1, false);
        solve(count, col, d1, d2, 0, n);
        return count;
    }
};