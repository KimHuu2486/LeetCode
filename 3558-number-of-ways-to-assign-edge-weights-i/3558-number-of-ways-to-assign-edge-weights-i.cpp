class Solution {
public:
    int DFS(const vector<vector<int>>& adj, int curNode, int parent) {
        int currentMax = 0;

        for (const int& v : adj[curNode]) {
            if (v != parent) {
                currentMax = max(currentMax, 1 + DFS(adj, v, curNode));
            }
        }

        return currentMax;
    }

    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1)
                res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        const int MOD = 1e9 + 7;
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1, vector<int>());

        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int maxDepth = DFS(adj, 1, -1);

        return power(2, maxDepth - 1, MOD);
    }
};