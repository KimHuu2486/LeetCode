class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>Road(m,vector<int>(n,0));
        for (int i = 0; i<m; i++){
            if (obstacleGrid[i][0] != 1){
                Road[i][0] = 1;
            }
            else break;
        }
        for (int j = 0; j<n; j++){
            if (obstacleGrid[0][j] != 1){
                Road[0][j] = 1;
            }
            else break;
        }
        for (int i = 1; i<m; i++){
            for (int j = 1; j<n; j++){
                if (obstacleGrid[i][j] == 1){
                    Road[i][j] = 0;
                }
                else{
                    Road[i][j] = Road[i][j-1] + Road[i-1][j];
                }
            }
        }
        return Road[m-1][n-1];
    }
};