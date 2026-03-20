class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, INT_MAX));

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                set<int> st;

                for (int r = i; r < i + k; r++) {
                    for (int c = j; c < j + k; c++) {
                        st.insert(grid[r][c]);
                    }
                }

                if (st.size() < 2) {
                    ans[i][j] = 0;
                } else {
                    for (auto it = next(st.begin()); it != st.end(); ++it) {
                        ans[i][j] = min(ans[i][j], *it - *prev(it));
                    }
                }
            }
        }

        return ans;
    }
};