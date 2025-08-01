class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n== 1) return {0};
        vector<vector<int>>adj(n);
        vector<int>degree(n);
        for (auto edge:edges){
            int u = edge[0], v =edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        queue<int>leaves;
        for (int i = 0; i<n; i++){
            if (degree[i] == 1){
                leaves.push(i);
            }
        }
        int remain = n;
        while (remain>2){
            int leaf = leaves.size();
            remain -= leaf;
            for (int i = 0; i<leaf; i++){
                int cur = leaves.front();
                leaves.pop();
                for (int v: adj[cur]){
                    degree[v]--;
                    if (degree[v] == 1){
                        leaves.push(v);
                    }
                }
            }
        };
        vector<int>ans;
        while(!leaves.empty()){
            ans.push_back(leaves.front());
            leaves.pop();
        }
        return ans;
        
    }
};