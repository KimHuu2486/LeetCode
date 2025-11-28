class Solution {
public:
    void dfs(vector<int>&parent, vector<vector<int>>&child, vector<int>&values, int k, int u, int& cnt) {
        if (child[u].size() != 0) {
            for (int v: child[u]) {
                dfs(parent, child, values, k, v, cnt);
            }
        }
        if (values[u] % k == 0) {
            cnt++;
        }
        else {
            values[parent[u]] = (values[parent[u]] + values[u]) % k;
        }
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {    
        vector<vector<int>>adj(n, vector<int>());
        for (auto& e: edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>parent(n, INT_MIN);
        vector<vector<int>>child(n, vector<int>());
        parent[0] = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v: adj[u]) {
                if (parent[u] != v) {
                    parent[v] = u;
                    child[u].push_back(v);
                    q.push(v);
                }
            }
        }
        int cnt = 0;
        dfs(parent, child, values, k, 0, cnt);
        return cnt;
    }
};