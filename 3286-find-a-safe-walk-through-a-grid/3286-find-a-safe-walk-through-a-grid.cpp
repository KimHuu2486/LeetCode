class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    struct node {
        int x, y, health;
    };
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        queue<node>q;
        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;
        
        q.push({0, 0, startHealth});
        visited[0][0] = startHealth;

        while (!q.empty()) {
            node cur = q.front();
            q.pop();

            if (cur.health < visited[cur.x][cur.y]) continue;

            if (cur.x == m - 1 && cur.y == n - 1 && cur.health >= 1) {
                return true;
            }

            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int nextHealth = cur.health - grid[nx][ny];

                    if (nextHealth >= 1 && nextHealth > visited[nx][ny]) {
                        visited[nx][ny] = nextHealth;
                        q.push({nx, ny, nextHealth});
                    }
                }
            }
        }
        
        return false; 
    }
};