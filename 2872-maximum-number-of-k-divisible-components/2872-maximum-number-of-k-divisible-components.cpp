class Solution {
public:
    vector<vector<int>>adj;
    void dfs(vector<int>&values, int k, int parent, int u, int& cnt) {
        for (int v: adj[u]) {
            if (v != parent) {
                dfs(values, k, u, v, cnt);
            }
        }
        if (values[u] % k == 0) {
            cnt++;
        }
        else {
            values[parent] = (values[parent] + values[u]) % k;
        }
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {    
        adj.resize(n, vector<int>());
        for (auto& e: edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt = 0;
        dfs(values, k, -1, 0, cnt);
        return cnt;
    }
};