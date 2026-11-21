class Solution {
public:
    void dfs(int cur,
             const vector<vector<int>>& adj,
             const string& s,
             vector<int>& last,
             vector<int>& newParent) {

        int c = s[cur] - 'a';

        int prev = last[c];

        if (last[c] != -1) {
            newParent[cur] = last[c];
        }

        last[c] = cur;

        for (int next : adj[cur]) {
            dfs(next, adj, s, last, newParent);
        }

        last[c] = prev;
    }

    int calcSize(int cur,
                 const vector<vector<int>>& adj,
                 vector<int>& answer) {

        int size = 1;

        for (int next : adj[cur]) {
            size += calcSize(next, adj, answer);
        }

        answer[cur] = size;
        return size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;
        vector<int> last(26, -1);

        dfs(0, adj, s, last, newParent);

        vector<vector<int>> newAdj(n);

        for (int i = 1; i < n; i++) {
            newAdj[newParent[i]].push_back(i);
        }

        vector<int> answer(n, 0);

        calcSize(0, newAdj, answer);

        return answer;
    }
};
