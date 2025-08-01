class Solution {
public:
    void solve(int &count, vector<bool>col, vector<bool>d1, vector<bool>d2, vector<int>pos, int i, int n){
        if (i == n){
            count++;
            return;
        }
        for (int j = 0; j<n ;j++){
            if (col[j] || d1[i-j+n-1] || d2[i+j]) continue;
            pos[i] =j;
            col[j] = 1;
            d1[i-j+n-1] = 1;
            d2[i+j] = 1;
            solve(count, col, d1, d2, pos,i+1, n);
            col[j] = 0;
            d1[i-j+n-1] = 0;
            d2[i+j] = 0;
        }
    }
    int totalNQueens(int n) {
        int count = 0;
        vector<bool>col(n, 0);
        vector<bool>d1(2*n-1, 0);
        vector<bool>d2(2*n - 1, 0);
        vector<int>pos(n, -1);
        solve(count, col, d1, d2, pos, 0, n);
        return count;
    }
};