class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> prefixSum(m, vector<int>(n, 0));
        prefixSum[0][0] = mat[0][0];
        for (int i = 1; i < m; i++) {
            prefixSum[i][0] = prefixSum[i - 1][0] + mat[i][0];
        }
        for (int j = 1; j < n; j++) {
            prefixSum[0][j] = prefixSum[0][j - 1] + mat[0][j];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] -
                                  prefixSum[i - 1][j - 1] + mat[i][j];
            }
        }

        for (int k = min(m, n); k > 0; k--) {
            for (int i = 0; i <= m - k; i++) {
                for (int j = 0; j <= n - k; j++) {
                    int curSum = prefixSum[i + k - 1][j + k - 1];
                    if (i == 0 && j != 0) {
                        curSum -= prefixSum[i + k - 1][j - 1];
                    } else if (i != 0 && j == 0) {
                        curSum -= prefixSum[i - 1][j + k - 1];
                    } else if (i != 0 && j != 0) {
                        curSum -= prefixSum[i + k - 1][j - 1] +
                                  prefixSum[i - 1][j + k - 1] -
                                  prefixSum[i - 1][j - 1];
                    }
                    if (curSum <= threshold) {
                        return k;
                    }
                }
            }
        }

        return 0;
    }
};