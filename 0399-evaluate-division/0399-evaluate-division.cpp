class Solution {
private:
    struct edge {
        string v;
        double w;
    };
    unordered_map<string, vector<struct edge>> adj;

public:
    double dfs(unordered_set<string>& visited, string u, string target,
               double div) {
        if (u == target) {
            return div;
        } else {
            visited.insert(u);
            for (auto& next : adj[u]) {
                if (visited.find(next.v) == visited.end()) {
                    double tmp = dfs(visited, next.v, target, div * next.w);
                    if (tmp != -1.0)
                        return tmp;
                }
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); i++) {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }
        vector<double> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            if (adj.find(queries[i][0]) == adj.end() ||
                adj.find(queries[i][1]) == adj.end()) {
                ans[i] = -1.0;
            } else {
                unordered_set<string> visited;
                ans[i] = dfs(visited, queries[i][0], queries[i][1], 1.0);
            }
        }
        return ans;
    }
};