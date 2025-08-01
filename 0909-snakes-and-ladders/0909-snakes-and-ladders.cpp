class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> road(n * n + 1);
        vector<bool> visited(n * n + 1, false);
        int idx = 1;
        for (int i = n - 1; i >= 0; i--) {
            if ((n - 1 - i) % 2 == 0) {
                for (int j = 0; j < n; j++)
                    road[idx++] = board[i][j];
            } else {
                for (int j = n - 1; j >= 0; j--)
                    road[idx++] = board[i][j];
            }
        }

        queue<pair<int, int>> q;
        q.push({1, 0});
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            visited[cur.first] = true;
            for (int i = 1; i <= 6 && i + cur.first <= n * n; i++) {
                int next = cur.first + i;
                if (road[next] != -1) {
                    next = road[next];
                }
                if (!visited[next]) {
                    visited[next] = true;
                    if (next == n * n)
                        return cur.second + 1;
                    q.push({next, cur.second + 1});
                }
            }
        }
        return -1;
    }
};