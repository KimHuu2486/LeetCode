class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        const long long INF = (1LL << 60);
        long long dist[26][26];

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++)
                dist[i][j] = (i == j ? 0 : INF);
        }

        for (int i = 0; i < (int)original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], 1LL * cost[i]);
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                if (dist[i][k] == INF)
                    continue;
                for (int j = 0; j < 26; j++) {
                    if (dist[k][j] == INF)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        if (source.size() != target.size())
            return -1;

        long long ans = 0;
        for (int i = 0; i < (int)source.size(); i++) {
            int s = source[i] - 'a';
            int t = target[i] - 'a';
            if (dist[s][t] == INF)
                return -1;
            ans += dist[s][t];
        }
        return ans;
    }
};