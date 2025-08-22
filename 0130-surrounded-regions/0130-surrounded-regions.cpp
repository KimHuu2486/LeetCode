class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i,
             int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            visited[i][j] || board[i][j] == 'X')
            return;
        visited[i][j] = true;
        dfs(board, visited, i - 1, j);
        dfs(board, visited, i, j - 1);
        dfs(board, visited, i + 1, j);
        dfs(board, visited, i, j + 1);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                dfs(board, visited, i, 0);
            }
            if (board[i][n - 1]) {
                dfs(board, visited, i, n - 1);
            }
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                dfs(board, visited, 0, j);
            }
            if (board[m - 1][j] == 'O') {
                dfs(board, visited, m - 1, j);
            }
        }
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (!visited[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};