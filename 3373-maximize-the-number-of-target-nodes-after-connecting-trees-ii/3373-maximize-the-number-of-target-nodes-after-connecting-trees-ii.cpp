class Solution {
public:
    void DFS(const vector<vector<int>>&adj, vector<int>&color, int u, int parent, int&even, int&odd){
        if (color[u] == 0){
            even++;
        } 
        else odd++;
        for (int v: adj[u]){
            if (v != parent){
                color[v] = 1 - color[u];
                DFS(adj, color, v, u, even, odd);
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> adj1(n), adj2(m);
        for (int i = 0; i < n - 1; i++) {
            int u = edges1[i][0];
            int v = edges1[i][1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        for (int i = 0; i < m - 1; i++) {
            int u = edges2[i][0];
            int v = edges2[i][1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        vector<int>color1(n, -1);
        vector<int>color2(m, -1);
        int even1 = 0, even2 = 0, odd1 = 0, odd2 = 0;
        color1[0] = 0;
        DFS(adj1, color1, 0, -1, even1, odd1);
        color2[0] = 0;
        DFS(adj2, color2, 0, -1, even2, odd2);
        int maxD2 = max(even2, odd2);
        vector<int>ans(n, maxD2);
        for (int i = 0; i<n; i++){
            ans[i] += (color1[i] == 0 ? even1 : odd1);
        }
        return ans;
    }
};