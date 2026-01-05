class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int cnt = 0;
        long long ans = 0LL;
        int n = matrix.size();
        int minElement = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] < 0) {
                    cnt++;
                }
                int cur = abs(matrix[i][j]);
                minElement = min(minElement, cur);
                ans += cur;
            }
        }
        return cnt % 2 == 0 ? ans : ans - 2 * minElement;
    }
};