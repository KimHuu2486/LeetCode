class Solution {
public:
    const int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void Move(vector<vector<char>> &grid, int x, int y) {
        queue<pair<int,int>>q;
        q.push({x, y});
        grid[x][y] = '0';
        while(!q.empty()){
            auto[curX, curY] = q.front();
            q.pop();
            for (int i = 0; i<4; i++){
                int newX = curX + direction[i][0];
                int newY = curY + direction[i][1];
                if (newX>=0 && newX <grid.size() && newY>=0 && newY<grid[0].size() && grid[newX][newY] == '1'){
                    q.push({newX, newY});
                    grid[newX][newY] = '0';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, 0));
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visit[i][j]) {
                    count++;
                    Move(grid, i, j);
                }
            }
        }
        return count;
    }
};