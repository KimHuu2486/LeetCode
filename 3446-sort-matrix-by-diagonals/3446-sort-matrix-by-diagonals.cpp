class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int r = 0; r < n; r++) {
            int i = r;
            int j = 0;
            vector<int> tmp;
            while (i < n) {
                tmp.push_back(grid[i++][j++]);
            }
            sort(tmp.begin(), tmp.end(), greater<int>());
            i = r;
            j = 0;
            for (int cur : tmp) {
                grid[i++][j++] = cur;
            }
        }
        for (int c = 1; c < n; c++) {
            int i = 0;
            int j = c;
            vector<int> tmp;
            while (j < n) {
                tmp.push_back(grid[i++][j++]);
            }
            sort(tmp.begin(), tmp.end());
            i = 0;
            j = c;
            for (int cur : tmp) {
                grid[i++][j++] = cur;
            }
        }
        return grid;
    }
};