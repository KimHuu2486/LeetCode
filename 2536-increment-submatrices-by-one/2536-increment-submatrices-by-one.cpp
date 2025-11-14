class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (auto& cur : queries) {
            for (int i = cur[0]; i <= cur[2]; i++) {
                ans[i][cur[1]]++;
                if (cur[3] + 1 < n) {
                    ans[i][cur[3] + 1]--;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                ans[i][j] += ans[i][j - 1];
            }
        }
        return ans;
    }
};