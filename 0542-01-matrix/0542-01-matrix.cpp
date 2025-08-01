class Solution {
public:
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,int>>bfs;
        for (int i = 0; i<m; i++){
            for (int j = 0; j<n; j++){
                if (mat[i][j]==0) {
                    bfs.push({i, j});
                }
                else {
                    mat[i][j] = INT_MAX;
                }
            }
        }
        while (!bfs.empty()){
            auto cur = bfs.front();
            bfs.pop();
            for (int i = 0; i<4; i++){
                int newX = cur.first + dx[i];
                int newY = cur.second + dy[i];
                if (newX>=0 && newX <m && newY >=0 && newY <n && mat[newX][newY] > mat[cur.first][cur.second] + 1){
                    mat[newX][newY] = mat[cur.first][cur.second] + 1;
                    bfs.push({newX, newY});
                }
            }
        }
        return mat;    
    }
};