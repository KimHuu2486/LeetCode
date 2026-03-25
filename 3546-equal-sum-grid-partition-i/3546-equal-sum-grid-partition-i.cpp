class Solution {
public:
    bool canPartition(vector<long long>& vec) {
        int n = vec.size();
        if (n < 2)
            return false;

        long long totalSum = accumulate(vec.begin(), vec.end(), 0LL);
        long long currentLeftSum = 0;

        for (int i = 0; i < n - 1; i++) {
            currentLeftSum += vec[i];
            if (currentLeftSum * 2 == totalSum) {
                return true;
            }
        }
        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<long long> horizontalSum(m, 0LL);
        vector<long long> verticalSum(n, 0LL);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                horizontalSum[i] += grid[i][j];
                verticalSum[j] += grid[i][j];
            }
        }

        return canPartition(horizontalSum) || canPartition(verticalSum);
    }
};