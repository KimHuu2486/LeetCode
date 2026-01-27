class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n, vector<pair<int,int>>());
        for (auto& edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2] * 2});
        }

        vector<int>dis(n, INT_MAX);
        dis[0] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({dis[0], 0});
        vector<bool>visited(n, false);
        
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int d = cur.first, u = cur.second;
            if (visited[u]) continue;

            for (auto nxt: adj[u]) {
                int v = nxt.first, w = nxt.second;
                if (visited[v]) {
                    continue;
                }
                
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.push({dis[v], v});
                }
            }
        }

        return dis[n - 1] == INT_MAX ? -1 : dis[n - 1];
    }
};