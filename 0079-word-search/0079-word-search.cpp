class Solution {
public:
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    bool dfs(vector<vector<char>>& board, int m, int n, string word, int x,
             int y, int index, vector<vector<bool>>& visited) {
        if (index == word.size())
            return 1;
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] ||
            board[x][y] != word[index])
            return false;
        visited[x][y] = 1;
        for (int k = 0; k < 4; k++) {
            int newX = x + dx[k];
            int newY = y + dy[k];
            if (dfs(board, m, n, word, newX, newY, index + 1, visited))
                return 1;
        }
        visited[x][y] = 0;
        return 0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, m, n, word, i, j, 0, visited))
                        return 1;
                }
            }
        }
        return 0;
    }
};