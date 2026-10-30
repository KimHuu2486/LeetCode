class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<long long>> dist(
            n, vector<long long>(k + 1, INT_MAX)
        );

        // {distance, node, consecutive_count}
        using State = tuple<long long, int, int>;

        priority_queue<
            State,
            vector<State>,
            greater<State>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, cnt] = pq.top();
            pq.pop();

            if (d > dist[u][cnt]) continue;

            if (u == n - 1) return (int)d;

            for (auto [v, w] : adj[u]) {
                int nextCnt = (labels[u] == labels[v])
                            ? cnt + 1
                            : 1;

                if (nextCnt > k) continue;

                long long newDist = d + w;

                if (newDist < dist[v][nextCnt]) {
                    dist[v][nextCnt] = newDist;
                    pq.push({newDist, v, nextCnt});
                }
            }
        }

        return -1;
    }
};