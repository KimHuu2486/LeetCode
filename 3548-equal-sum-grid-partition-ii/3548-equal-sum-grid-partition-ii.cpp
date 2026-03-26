class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long total = 0;
        unordered_map<int, int> mpTotal, mpTop, mpLeft;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
                mpTotal[grid[i][j]]++;
            }
        }

        long long s1 = 0;
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                s1 += grid[i][j];
                mpTop[grid[i][j]]++;
            }
            long long s2 = total - s1;
            if (s1 == s2)
                return true;

            long long x1 = s1 - s2;
            if (x1 > 0 && x1 <= 1000000 && mpTop[x1] > 0) {
                if (isValid(grid, (int)x1, 0, i, 0, n - 1))
                    return true;
            }

            long long x2 = s2 - s1;
            if (x2 > 0 && x2 <= 1000000 && (mpTotal[x2] - mpTop[x2] > 0)) {
                if (isValid(grid, (int)x2, i + 1, m - 1, 0, n - 1))
                    return true;
            }
        }

        s1 = 0;
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) {
                s1 += grid[i][j];
                mpLeft[grid[i][j]]++;
            }
            long long s2 = total - s1;
            if (s1 == s2)
                return true;

            long long x1 = s1 - s2;
            if (x1 > 0 && x1 <= 1000000 && mpLeft[x1] > 0) {
                if (isValid(grid, (int)x1, 0, m - 1, 0, j))
                    return true;
            }
            long long x2 = s2 - s1;
            if (x2 > 0 && x2 <= 1000000 && (mpTotal[x2] - mpLeft[x2] > 0)) {
                if (isValid(grid, (int)x2, 0, m - 1, j + 1, n - 1))
                    return true;
            }
        }
        return false;
    }

private:
    bool isValid(const vector<vector<int>>& grid, int x, int r1, int r2, int c1,
                 int c2) {
        int r = r2 - r1 + 1;
        int c = c2 - c1 + 1;

        // Điều kiện 1: Sau khi bỏ 1 ô, phần đó không được rỗng (phải có > 1 ô
        // ban đầu)
        if (r * c <= 1)
            return false;

        // Điều kiện 2: Tính kết nối
        if (r > 1 && c > 1)
            return true; // Hình chữ nhật lớn luôn kết nối
        if (r == 1)
            return (grid[r1][c1] == x ||
                    grid[r1][c2] == x); // Hàng đơn: bỏ 2 đầu
        if (c == 1)
            return (grid[r1][c1] == x ||
                    grid[r2][c1] == x); // Cột đơn: bỏ 2 đầu

        return false;
    }
};