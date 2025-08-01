class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>>adj(n);
        for (int i = 0; i<n; i++){
            for (int j = i+1; j<n; j++){
                int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, dis});
                adj[j].push_back({i, dis});
            }
        }
        vector<bool>visited(n, false);
        vector<int>d(n, INT_MAX);
        int ans = 0;
        d[0] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>heap;
        heap.push({0, 0});
        while (!heap.empty()){
            auto cur = heap.top();
            heap.pop();
            if (visited[cur.second]) continue;
            visited[cur.second] = true;
            ans+= cur.first;
            for (auto next: adj[cur.second]){
                if (!visited[next.first] && d[next.first] > next.second){
                    d[next.first] = next.second;
                    heap.push({d[next.first], next.first});
                }
            }
        }
        return ans;
    }
};