class Solution {
public:
    int DFS(int u, int parent, int distance, const vector<vector<int>>& adj){
        if (distance<0) return 0;
        int cnt =1 ;
        for (int v : adj[u]){
            if (v!=parent){
                cnt+=DFS(v, u, distance-1, adj);
            }
        }
        return cnt;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n =edges1.size()+1, m = edges2.size()+1;
        vector<vector<int>>adj1(n), adj2(m);
        for (int i = 0; i<n-1;i++){
            int  u = edges1[i][0];
            int v =edges1[i][1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        for (int i = 0; i<m-1;i++){
            int  u = edges2[i][0];
            int v =edges2[i][1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        int maxD2 = 0;
        for (int i = 0; i<m; i++){
            maxD2 = max(maxD2, DFS(i, -1, k-1, adj2));
        }
        vector<int>ans(n, maxD2);
        for (int i = 0; i<n; i++){
            ans[i] += DFS(i, -1, k, adj1);
        }
        return ans;
    }
};