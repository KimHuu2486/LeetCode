class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minCol = INT_MAX, maxCol = INT_MIN, minRow = INT_MAX,
            maxRow = INT_MIN;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    minCol = min(j, minCol);
                    maxCol = max(j, maxCol);
                    minRow = min(i, minRow);
                    maxRow = max(i, maxRow);
                }
            }
        }
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};