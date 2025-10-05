class Solution {
private:
    int m, n;
    vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i,
             int j) {
        visited[i][j] = true;
        for (auto& d : direction) {
            int x = i + d[0];
            int y = j + d[1];
            if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] ||
                heights[i][j] > heights[x][y])
                continue;
            dfs(heights, visited, x, y);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> Pacific(m, vector<bool>(n, false));
        vector<vector<bool>> Atlantic(m, vector<bool>(n, false));

        for (int j = 0; j < n; j++) {
            dfs(heights, Pacific, 0, j);
            dfs(heights, Atlantic, m - 1, j);
        }
        for (int i = 0; i < m; i++) {
            dfs(heights, Pacific, i, 0);
            dfs(heights, Atlantic, i, n - 1);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (Pacific[i][j] && Atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};