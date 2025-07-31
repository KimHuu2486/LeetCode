class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (m==1|| n==1){
            return 1;
        }
        int end = min(m, n);
        int count = 0;
        for (int i = m - 1; i>0; i--){
            count++;
            int j = 0;
            for (int k = i; k< m; k++){
                if (j>= min(count,end)){
                    break;
                }
                if (matrix[k][j]!=matrix[i][0]){
                    return 0;
                }
                j++;
            }
        }
        count = 0;
        for (int j = n -1; j>=0; j--){
            count++;
            int i = 0;
            for (int k = j; k<n; k++){
                if (i>=min(count, end)){
                    break;
                }
                if (matrix[i][k]!=matrix[0][j]){
                    return 0;
                }
                i++;
            }
        }
        //for (int i = 1; i<min(m,n); i++){
          //  if (matrix[i][i]!=matrix[0][0]){
            //    return 0;
            //}
        //}
        return 1;
    }
};