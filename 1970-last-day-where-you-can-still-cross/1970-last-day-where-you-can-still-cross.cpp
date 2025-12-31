class Solution {
public:
    int directions[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

    int find(int v, vector<int>& parent) {
        while (parent[v] != v) {
            parent[v] = parent[parent[v]];
            v = parent[v];
        }
        return v;
    }

    void Union(int a, int b, vector<int>& parent, vector<int>& sz) {
        a = find(a, parent);
        b = find(b, parent);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = row * col;
        int TOP = n, BOTTOM = n + 1;

        vector<int> parent(n + 2), sz(n + 2, 1);
        for (int i = 0; i < n + 2; i++) parent[i] = i;

        vector<char> grid(n, 1);

        auto idx = [&](int r, int c) { return r * col + c; };

        for (int k = n - 1; k >= 0; k--) {
            int x = cells[k][0] - 1;
            int y = cells[k][1] - 1;
            int u = idx(x, y);

            grid[u] = 0;

            if (x == 0) Union(TOP, u, parent, sz);
            if (x == row - 1) Union(BOTTOM, u, parent, sz);

            for (int d = 0; d < 4; d++) {
                int nx = x + directions[d][0];
                int ny = y + directions[d][1];
                if (0 <= nx && nx < row && 0 <= ny && ny < col) {
                    int v = idx(nx, ny);
                    if (grid[v] == 0) Union(u, v, parent, sz);
                }
            }

            if (find(TOP, parent) == find(BOTTOM, parent)) return k;
        }
        return 0;
    }
};