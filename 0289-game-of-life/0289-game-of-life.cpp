class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> prev(m + 2, vector<int>(n + 2, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prev[i][j] = board[i - 1][j - 1];
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int temp = 0;
                for (int k = i - 1; k <= i + 1; k++) {
                    for (int h = j - 1; h <= j + 1; h++) {
                        temp += prev[k][h];
                    }
                }
                if (prev[i][j] == 1) {
                    temp--;
                    if (temp < 2 || temp > 3)
                        board[i - 1][j - 1] = 0;
                    else
                        board[i - 1][j - 1] = 1;
                } else {
                    if (temp == 3)
                        board[i - 1][j - 1] = 1;
                }
            }
        }
    }
};