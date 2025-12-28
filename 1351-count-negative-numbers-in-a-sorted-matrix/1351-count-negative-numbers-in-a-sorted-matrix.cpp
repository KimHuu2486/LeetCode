class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        auto binarySearch = [&](int row, int left, int right) {
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (grid[row][mid] < 0) {
                    right = mid;
                }
                else {
                    left = mid + 1;
                }
            }
            return right;
        };

        int ans = 0;
        int right = n - 1;
        for (int i = 0; i < m; i++) {
            if (grid[i][right] >= 0) {
                continue;
            }
            int cur = binarySearch(i, 0, right);
            ans += n - cur;
            right = cur;
        }
        return ans;
    }
};