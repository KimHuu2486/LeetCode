class Solution {
public:
    bool checkMagicSquare(const vector<vector<int>>& grid, int row, int col, int k) {
        int target = 0;
        for (int i = row; i < row + k; i++) {
            int sumRow = 0;
            for (int j = col; j < col + k; j++) {
                sumRow += grid[i][j];
            }
            if (i == row) {
                target = sumRow;
            }
            else {
                if (target != sumRow) {
                    return false;
                }
            }
        }

        for (int j = col; j < col + k; j++) {
            int sumCol = 0;
            for (int i = row; i < row + k; i++) {
                sumCol += grid[i][j];
            }
            if (sumCol != target) {
                return false;
            }
        }

        int sumDiagonal = 0;
        int x = row, y = col;
        while (x < row + k) {
            sumDiagonal += grid[x][y];
            x++;
            y++;
        }
        if (sumDiagonal != target) {
            return false;
        }

        int sumAntiDiagonal = 0;
        x = row;
        y = col + k - 1;
        while (x < row + k) {
            sumAntiDiagonal += grid[x][y];
            x++;
            y--;
        }
        if (sumAntiDiagonal != target) {
            return false;
        }
        return true;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int k = min(m, n);
        while (k > 1) {
            for (int i = 0; i <= m - k; i++) {
                for (int j = 0; j <= n - k; j++) {
                    if (checkMagicSquare(grid, i, j, k)) {
                        return k;
                    }
                }
            }
            k--;
        }
        return 1;
    }
};