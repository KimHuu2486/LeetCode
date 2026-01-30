class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<string>& original, vector<string>& changed,
                          vector<int>& cost) {
        const long long INF = (1LL << 60);
        int n = (int)source.size();

        vector<string> all;
        all.reserve(original.size() * 2);
        for (auto& s : original)
            all.push_back(s);
        for (auto& s : changed)
            all.push_back(s);
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());

        int m = (int)all.size();
        unordered_map<string, int> id;
        id.reserve(m * 2);
        id.max_load_factor(0.7f);
        for (int i = 0; i < m; i++)
            id[all[i]] = i;

        vector<vector<long long>> dist(m, vector<long long>(m, INF));
        for (int i = 0; i < m; i++)
            dist[i][i] = 0;

        for (int i = 0; i < (int)original.size(); i++) {
            int u = id[original[i]];
            int v = id[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < m; k++) {
            for (int i = 0; i < m; i++)
                if (dist[i][k] < INF) {
                    for (int j = 0; j < m; j++)
                        if (dist[k][j] < INF) {
                            long long nd = dist[i][k] + dist[k][j];
                            if (nd < dist[i][j])
                                dist[i][j] = nd;
                        }
                }
        }

        // Build a trie for all patterns in S
        struct Node {
            int next[26];
            int patId;
            Node() : patId(-1) { fill(next, next + 26, -1); }
        };
        vector<Node> trie;
        trie.reserve(1 + 50000);
        trie.push_back(Node());

        auto insertTrie = [&](const string& s, int pid) {
            int cur = 0;
            for (char ch : s) {
                int c = ch - 'a';
                if (trie[cur].next[c] == -1) {
                    trie[cur].next[c] = (int)trie.size();
                    trie.push_back(Node());
                }
                cur = trie[cur].next[c];
            }
            trie[cur].patId = pid;
        };

        int maxLen = 0;
        for (int i = 0; i < m; i++) {
            insertTrie(all[i], i);
            maxLen = max(maxLen, (int)all[i].size());
        }

        // dp[i] = min cost to convert prefix length i
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] >= INF)
                continue;

            // keep character if same
            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            // choose a segment [i..j]
            int uNode = 0, vNode = 0;
            for (int j = i; j < n && j - i + 1 <= maxLen; j++) {
                int cu = source[j] - 'a';
                int cv = target[j] - 'a';

                if (uNode != -1)
                    uNode = trie[uNode].next[cu];
                if (vNode != -1)
                    vNode = trie[vNode].next[cv];

                if (uNode == -1 || vNode == -1)
                    break;

                int uPat = trie[uNode].patId;
                int vPat = trie[vNode].patId;

                if (uPat != -1 && vPat != -1) {
                    long long w = dist[uPat][vPat];
                    if (w < INF) {
                        dp[j + 1] = min(dp[j + 1], dp[i] + w);
                    }
                }
            }
        }

        return (dp[n] >= INF ? -1 : dp[n]);
    }
};