class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix[0].size() -1;
        while (row<matrix.size() && col>=0){
            if (matrix[row][col] == target) return 1;
            else if (matrix[row][col]>target) col--;
            else row++;
        }
        return 0;
    }
};