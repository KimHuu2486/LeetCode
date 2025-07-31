class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>pascal;
        vector<int>row;
        row.push_back(1);
        pascal.push_back(row);
        for (int i = 2; i<=rowIndex+1; i++){
            row.erase(row.begin(), row.end());
            row.push_back(1);
            for (int j =1; j<i-1; j++){
                int temp = pascal[i-2][j-1] + pascal[i-2][j];
                row.push_back(temp);
            }
            row.push_back(1);
            pascal.push_back(row);
        }
        return pascal[rowIndex];
    }
};