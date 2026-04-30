class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> prev(n, vector<int>(k + 1, INT_MIN));

        for (int i = 0; i < m; i++) {
            vector<vector<int>> curr(n, vector<int>(k + 1, INT_MIN));

            for (int j = 0; j < n; j++) {
                int cost = grid[i][j] > 0 ? 1 : 0;
                int gain = grid[i][j];

                int limit = min(k, i + j);

                if (i == 0 && j == 0) {
                    curr[0][0] = 0;
                    continue;
                }

                for (int c = cost; c <= limit; c++) {
                    int best = INT_MIN;

                    if (i > 0 && prev[j][c - cost] != INT_MIN) {
                        best = max(best, prev[j][c - cost] + gain);
                    }

                    if (j > 0 && curr[j - 1][c - cost] != INT_MIN) {
                        best = max(best, curr[j - 1][c - cost] + gain);
                    }

                    curr[j][c] = best;
                }
            }

            prev = curr;
        }

        int ans = INT_MIN;
        for (int c = 0; c <= k; c++) {
            ans = max(ans, prev[n - 1][c]);
        }

        return ans == INT_MIN ? -1 : ans;
    }
};