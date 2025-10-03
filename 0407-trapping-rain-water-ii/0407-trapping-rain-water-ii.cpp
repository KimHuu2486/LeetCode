class Solution {
private:
    struct pos {
        int height, x, y;
        bool operator>(const pos& other) const { return height > other.height; }
    };
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        if (m <= 2 || n <= 2)
            return 0;
        priority_queue<pos, vector<pos>, greater<pos>> boundary;
        for (int i = 0; i < m; i++) {
            boundary.push({heightMap[i][0], i, 0});
            boundary.push({heightMap[i][n - 1], i, n - 1});
            heightMap[i][0] = heightMap[i][n - 1] = -1; // Visited
        }
        for (int j = 1; j < n - 1; j++) {
            boundary.push({heightMap[0][j], 0, j});
            boundary.push({heightMap[m - 1][j], m - 1, j});
            heightMap[0][j] = heightMap[m - 1][j] = -1; // Visited
        }
        int ans = 0, maxWaterLevel = 0;
        while (!boundary.empty()) {
            pos cur = boundary.top();
            boundary.pop();
            maxWaterLevel = max(maxWaterLevel, cur.height);
            for (int k = 0; k < 4; k++) {
                int nextX = cur.x + dx[k];
                int nextY = cur.y + dy[k];
                if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n ||
                    heightMap[nextX][nextY] == -1)
                    continue;
                int nextHeight = heightMap[nextX][nextY];
                if (nextHeight < maxWaterLevel) {
                    ans += maxWaterLevel - nextHeight;
                }
                heightMap[nextX][nextY] = -1; // Visited
                boundary.push({nextHeight, nextX, nextY});
            }
        }
        return ans;
    }
};