class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return 0;

        vector<pair<int,int>> thief;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    thief.push_back({i, j});
                }
            }
        }

        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        
        for (auto& t : thief) {
            q.push(t);
            dist[t.first][t.second] = 0;
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> max_safeness(n, vector<int>(n, -1));

        pq.push({dist[0][0], {0, 0}});
        max_safeness[0][0] = dist[0][0];

        while (!pq.empty()) {
            auto [safe, cell] = pq.top();
            auto [r, c] = cell;
            pq.pop();

            if (r == n - 1 && c == n - 1) return safe;

            if (safe < max_safeness[r][c]) continue;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    int next_safe = min(safe, dist[nr][nc]);
                    
                    if (next_safe > max_safeness[nr][nc]) {
                        max_safeness[nr][nc] = next_safe;
                        pq.push({next_safe, {nr, nc}});
                    }
                }
            }
        }

        return 0;
    }
};