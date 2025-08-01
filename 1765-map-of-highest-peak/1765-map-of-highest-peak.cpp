class Solution {
public:
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        queue<pair<int, int>>bfs;
        for (int i = 0; i<m; i++){
            for (int j = 0; j<n; j++){
                if (isWater[i][j] == 0){
                    isWater[i][j] = INT_MAX;
                }
                else {
                    isWater[i][j] = 0;
                    bfs.push({i,j});
                }
            }
        }
        while (!bfs.empty()){
            auto cur = bfs.front();
            bfs.pop();
            for (int i = 0; i<4; i++){
                int newX = cur.first+dx[i];
                int newY = cur.second+dy[i];
                if (newX>= 0 && newX<m && newY>=0 && newY<n && isWater[newX][newY] > isWater[cur.first][cur.second] + 1){
                    isWater[newX][newY] = isWater[cur.first][cur.second] + 1;
                    bfs.push({newX, newY});
                }
            }
        }
        return isWater;
    }
};