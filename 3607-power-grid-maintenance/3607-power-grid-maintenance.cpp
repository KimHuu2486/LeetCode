class Solution {
public:
    void dfs(int id, int node, vector<vector<int>>& adj, vector<bool>& visited, unordered_map<int, set<int>>& mp, unordered_map<int, int>& mpp) {
        visited[node] = true;
        mp[id].insert(node);
        mpp[node] = id;
        for (auto& it: adj[node]) {
            if (!visited[it]) {
                dfs(id, it, adj, visited, mp, mpp);
            }
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>> adj(c + 1);
        for (auto& connect: connections) {
            adj[connect[1]].push_back(connect[0]);
            adj[connect[0]].push_back(connect[1]);
        }

        vector<bool> visited(c + 1, false);
        unordered_map<int, set<int>> mp;
        unordered_map<int, int> mpp;
        int id = 1;

        for (int i = 1; i <= c; i++) {
            if (!visited[i]) {
                dfs(id, i, adj, visited, mp, mpp);
                id++;
            }
        }

        vector<int> ans;

        for (auto &querry: queries) {
            int node = querry[1];
            int componentID = mpp[node];

            if (querry[0] == 1) {
                if (visited[node]) {
                    ans.push_back(node);
                }
                else if (mp[componentID].size() > 0) {
                    ans.push_back(*mp[componentID].begin());
                }
                else {
                    ans.push_back(-1);
                }
            }
            else {
                mp[componentID].erase(node);
                visited[node]= false;
            }
        }
        return ans;
    }
};