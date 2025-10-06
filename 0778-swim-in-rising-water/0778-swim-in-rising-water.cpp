class Solution {
private:
    const vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<pair<int, int>>> adj;
    vector<int> Distance;
    vector<bool> visited;

public:
    void Dijkstra(int source) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            heap;
        heap.push({Distance[source], source});
        while (!heap.empty()) {
            auto cur = heap.top();
            heap.pop();
            if (visited[cur.second])
                continue;
            visited[cur.second] = true;
            for (auto v : adj[cur.second]) {
                if (!visited[v.first] &&
                    Distance[v.first] > max(Distance[cur.second], v.second)) {
                    Distance[v.first] = max(Distance[cur.second], v.second);
                    heap.push({Distance[v.first], v.first});
                }
            }
        }
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        adj.resize(n * n, {});
        visited.resize(n * n, false);
        Distance.resize(n * n, INT_MAX);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int u = i * n + j;
                for (int k = 0; k < 4; k++) {
                    int newX = i + direction[k].first;
                    int newY = j + direction[k].second;
                    if (newX < 0 || newX >= n || newY < 0 || newY >= n)
                        continue;
                    int v = newX * n + newY;
                    adj[u].push_back({v, grid[newX][newY]});
                }
            }
        }
        Distance[0] = grid[0][0];
        Dijkstra(0);
        return Distance[n * n - 1];
    }
};