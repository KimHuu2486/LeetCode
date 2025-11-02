class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, -1));
        for (const auto& pos : walls) {
            grid[pos[0]][pos[1]] = 0;
        }
        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = 0;
        }

        for (const auto& guard : guards) {
            int r = guard[0], c = guard[1];

            for (int i = r - 1; i >= 0; i--) {
                if (grid[i][c] == 0) break;
                grid[i][c] = 1;
            }
            
            for (int i = r + 1; i < m; i++) {
                if (grid[i][c] == 0) break;
                grid[i][c] = 1;
            }
            
            for (int j = c - 1; j >= 0; j--) {
                if (grid[r][j] == 0) break;
                grid[r][j] = 1;
            }
            
            for (int j = c + 1; j < n; j++) {
                if (grid[r][j] == 0) break;
                grid[r][j] = 1;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == -1)
                    ans++;
            }
        }
        return ans;
    }
};