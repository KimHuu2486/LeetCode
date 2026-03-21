class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size(), n = grid[0].size();
        for (int step = 0; step < k; step++) {
            int col = y + step;
            for (int i = 0; i < k / 2; i++) {
                swap(grid[x + i][col], grid[x + k - 1 - i][col]);
            }
        }
        return grid;
    }
};