class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            heap;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        heap.push({grid[0][0], {0, 0}});
        ;
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        while (!heap.empty()) {
            auto it = heap.top();
            heap.pop();
            int height = it.first;
            int curx = it.second.first;
            int cury = it.second.second;
            if (curx == n - 1 && cury == n - 1)
                return height;
            if (visited[curx][cury]) continue;
            visited[curx][cury] = true;
            for (int i = 0; i < 4; i++) {
                int newx = curx + dx[i], newy = cury + dy[i];
                if (newx < 0 || newx >= n || newy < 0 || newy >= n || visited[newx][newy])
                    continue;
                heap.push({max(height, grid[newx][newy]), {newx, newy}});
            }
        }
        return 0;
    }
};