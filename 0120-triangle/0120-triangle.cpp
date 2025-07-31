class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<int>ans = triangle[row-1];
        for (int i = row-2; i>=0; i--){
            for (int j = 0; j<=i; j++){
                ans[j] = min(triangle[i][j]+ans[j], triangle[i][j] + ans[j+1]);
            }
        }
        return ans[0];
    }
};