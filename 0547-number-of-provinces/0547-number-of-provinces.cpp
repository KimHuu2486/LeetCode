class Solution {
public:
    void DFS(vector<vector<int>>& graph, vector<bool>& visited, int u) {
        visited[u] = true;
        for (int v = 0; v < graph.size(); ++v) {
            if (graph[u][v] == 1 && !visited[v]) {
                DFS(graph, visited, v);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>visited(n, false);
        int ans = 0;
        for (int i = 0; i<n; i++){
            if (!visited[i]){
                DFS(isConnected, visited, i);
                ans++;
            }
        }
        return ans;
    }
};