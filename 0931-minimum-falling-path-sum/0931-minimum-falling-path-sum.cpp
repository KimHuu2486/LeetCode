class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> road = matrix[n - 1];
        vector<int> roadTemp = road;
        for (int i = n - 2; i >= 0; i--) {
            road[0] =
                min(matrix[i][0] + roadTemp[0], matrix[i][0] + roadTemp[1]);
            for (int j = 1; j < n - 1; j++) {
                road[j] = min(matrix[i][j] + roadTemp[j - 1],
                              min(matrix[i][j] + roadTemp[j],
                                  matrix[i][j] + roadTemp[j + 1]));
            }
            road[n - 1] = min(matrix[i][n - 1] + roadTemp[n - 2],
                              matrix[i][n - 1] + roadTemp[n - 1]);
            roadTemp = road;
        }
        return *min_element(road.begin(), road.end());
    }
};