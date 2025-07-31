class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>vec;
        int headRow = 0;
        int tailCol = matrix[0].size() - 1;
        int tailRow = matrix.size() - 1;
        int headCol = 0;
        while (headRow<=tailRow && headCol<=tailCol){
            if (tailCol == headCol){
                for (int i = headRow; i<=tailRow; i++){
                    vec.push_back(matrix[i][headCol]);
                }
                return vec;
            }
            if (tailRow == headRow){
                for (int j =headCol; j<=tailCol; j++){
                    vec.push_back(matrix[headRow][j]);
                }
                return vec;
            }
            for (int j = headCol; j<tailCol; j++){
                vec.push_back(matrix[headCol][j]);
            }
            for (int i = headRow; i<tailRow; i++){
                vec.push_back(matrix[i][tailCol]);
            }
            for (int j = tailCol; j>headCol; j--){
                vec.push_back(matrix[tailRow][j]);
            }
            for (int i = tailRow; i>headRow; i--){
                vec.push_back(matrix[i][headCol]);
            }
            if (headRow == tailRow && headRow == headCol && headRow == tailCol){
                vec.push_back(matrix[headRow][headRow]);
            }
            headRow++; tailRow--; tailCol--; headCol++;
        }
        return vec;
    }
};