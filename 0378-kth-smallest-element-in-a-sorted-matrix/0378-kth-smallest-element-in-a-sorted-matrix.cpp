class Solution {
public:
    int countLessEqual(vector<vector<int>>&matrix, int x){
        int cnt = 0;
        int j = matrix.size()-1;
        for (int i = 0; i<matrix.size(); i++){
            while (j>=0 && matrix[i][j] > x){
                j--;
            }
            cnt+=(j+1);
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int res =-1;
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        while (left<=right){
            int mid = (left+right)/2;
            if (countLessEqual(matrix, mid) >=k){
                res = mid;
                right = mid -1;
            }
            else left = mid +1;
        }
        return res;
    }
};