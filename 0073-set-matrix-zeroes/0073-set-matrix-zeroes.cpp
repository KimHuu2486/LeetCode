class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool isFirstRow = 0;
        bool isFirstCol = 0;
        for (int i = 0; i<rows; i++){
            if (matrix[i][0] == 0){
                isFirstCol  =1;
                break;
            }
        }
        for (int j = 0; j<cols;j++){
            if (matrix[0][j] == 0){
                isFirstRow = 1;
                break;
            }
        }
        for (int i = 0; i<rows; i++){
            for (int j = 0; j<cols; j++){
                if (matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1 ; i<rows; i++){
            if(matrix[i][0] == 0){
                for (int j = 0; j<cols; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j =1 ; j<cols; j++){
            if (matrix[0][j] == 0){
                for (int i = 0; i<rows; i++){
                    matrix[i][j] = 0;
                }
            }
        }
        if (isFirstRow){
            for (int j = 0; j<cols; j++){
                matrix[0][j] = 0;
            }
        }
        if (isFirstCol){
            for (int i = 0; i<rows; i++){
                matrix[i][0] = 0;
            }
        }
    }
};