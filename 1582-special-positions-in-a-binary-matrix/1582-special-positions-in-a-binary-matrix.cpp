class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int>OnesRow(n, 0), OnesCol(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                OnesRow[i] += mat[i][j];
                OnesCol[j] += mat[i][j];
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    if (OnesRow[i] == 1 && OnesCol[j] == 1) {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};