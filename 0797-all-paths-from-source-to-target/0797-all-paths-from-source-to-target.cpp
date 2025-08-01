class Solution {
public:
    void DFS(vector<vector<int>>&graph, vector<vector<int>>&ans, vector<int>path, int u, int n){
        path.push_back(u);
        if (u == n-1) {
            ans.push_back(path);
            return;
        }
        for (int v : graph[u]){
            DFS(graph, ans, path, v, n);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>ans;
        vector<int>path;
        DFS(graph, ans, path, 0, n);
        return ans;
    }
};