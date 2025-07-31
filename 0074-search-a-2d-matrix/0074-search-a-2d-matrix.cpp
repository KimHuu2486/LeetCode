class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()){
            return false;
        }
        if (matrix[0][0]>target){
            return false;
        }
        if (matrix[matrix.size()-1][0]<target){
            for (int j =0; j<matrix[matrix.size()-1].size(); j++){
                if (matrix[matrix.size()-1][j]==target){
                return true;
                }
            }
            return false;
        }
        for (int i =0; i<matrix.size(); i++){
            if (matrix[i][0]>target){
                for (int j =0; j<matrix[i-1].size(); j++){
                    if (matrix[i-1][j]==target){
                        return true;
                    }
                }
                return false;
            }
            else if (matrix[i][0]==target){
                return true;
            }
        }
        return false;
    }
};