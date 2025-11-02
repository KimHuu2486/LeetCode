class Solution {
public:
    vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void sight(vector<vector<int>>& grid, int i, int j, pair<int,int> curDir) {
        i += curDir.first;
        j += curDir.second;
        while (i >= 0 && i <grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] != 0) {
            grid[i][j] = 1;
            i += curDir.first;
            j += curDir.second;
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, -1));
        for (const auto& pos: walls) {
            grid[pos[0]][pos[1]] = 0;
        }
        for (const auto& guard: guards) {
            grid[guard[0]][guard[1]] = 0;
        }
        for (const auto& guard: guards) {
            sight(grid, guard[0], guard[1], direction[0]);
            sight(grid, guard[0], guard[1], direction[1]);
            sight(grid, guard[0], guard[1], direction[2]);
            sight(grid, guard[0], guard[1], direction[3]);
        }
        int ans = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == -1) ans++;
            }
        }
        return ans;
    }
};