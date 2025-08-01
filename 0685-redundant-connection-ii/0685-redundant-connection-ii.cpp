class Solution {
public:
    int find(int v, vector<int>&parent){
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v], parent);
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>parent(n+1, 0), canA, canB;
        for (auto& edge: edges){
            if (parent[edge[1]] == 0){
                parent[edge[1]] = edge[0];
            }
            else{
                canA = {parent[edge[1]], edge[1]};
                canB = edge;
                edge[1] = 0;
            }
        }
        for (int i = 1; i<=n; i++) parent[i] = i;
        for (auto& edge: edges){
            int u = edge[0], v =edge[1];
            if (v == 0) continue;
            int root = find(u, parent);
            if (root == v){
                return canA.empty() ? edge : canA;
            }
            parent[v] = root;
        }
        return canB;
    }
};