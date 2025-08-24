class Solution {
public:
    bool isConnected(const string& s1, const string& s2) {
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
            if (s1[i] != s2[i])
                cnt++;
        }
        return cnt == 1;
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_map<string, vector<string>> adj;
        for (const string& s : bank) {
            if (isConnected(startGene, s)) {
                adj[startGene].push_back(s);
            }
        }
        for (int i = 0; i < bank.size(); i++) {
            for (int j = i + 1; j < bank.size(); j++) {
                if (isConnected(bank[i], bank[j])) {
                    adj[bank[i]].push_back(bank[j]);
                    adj[bank[j]].push_back(bank[i]);
                }
            }
        }
        unordered_set<string> visited;
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            visited.insert(cur.first);
            if (cur.first == endGene)
                return cur.second;
            for (const string& s : adj[cur.first]) {
                if (visited.find(s) == visited.end()) {
                    q.push({s, cur.second + 1});
                }
            }
        }
        return -1;
    }
};