class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> histogram(n, 0);
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    histogram[j]++;
                } else
                    histogram[j] = 0;
            }
            for (int j = 0; j < n; j++) {
                int min_h = histogram[j];
                for (int k = j; k >= 0 && min_h > 0; k--) {
                    min_h = min(histogram[k], min_h);
                    ans += min_h;
                }
            }
        }
        return ans;
    }
};