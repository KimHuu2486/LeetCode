class Solution {
public:
    struct Point {
        int x, y;
        Point(int i, int j) : x(i), y(j) {};
    };
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int> st;

        auto checkValid =
            [&m, &n](const Point& cur) {
                if (cur.x < 0 || cur.x >= m || cur.y < 0 || cur.y >= n)
                    return false;
                return true;
            };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                st.insert(grid[i][j]);

                for (int k = 1;; k++) {
                    int sum = 0;
                    Point top(i, j), right(i + k, j + k), bottom(i + 2 * k, j),
                        left(i + k, j - k);

                    if (!checkValid(right) || !checkValid(bottom) ||
                        !checkValid(left)) {
                        break;
                    }

                    for (int step = 0; step < k; step++) {
                        sum += grid[top.x][top.y];
                        sum += grid[right.x][right.y];
                        sum += grid[bottom.x][bottom.y];
                        sum += grid[left.x][left.y];

                        // top->right
                        top.x++;
                        top.y++;
                        // right->bottom
                        right.x++;
                        right.y--;
                        // bottom->left
                        bottom.x--;
                        bottom.y--;
                        // left->right
                        left.x--;
                        left.y++;
                    }

                    st.insert(sum);
                }
            }
        }

        vector<int>ans;
        for (auto it = st.rbegin(); it != st.rend() && ans.size() < 3; it++) {
            ans.push_back(*it);
        }
        return ans;
    }
};