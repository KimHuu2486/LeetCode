class Solution {
public:
    bool row[9][10] = {false};
    bool col[9][10] = {false};
    bool box[9][10] = {false};
    bool backtrack(vector<vector<char>>& board, int i, int j) {
        if (j > 8)
            return backtrack(board, i + 1, 0);
        if (i > 8)
            return true;
        if (board[i][j] != '.') {
            return backtrack(board, i, j + 1);
        } else {
            int boxIdx = (i / 3) * 3 + j / 3;
            for (int num = 1; num <= 9; num++) {
                if (!row[i][num] && !col[j][num] && !box[boxIdx][num]) {
                    row[i][num] = col[j][num] = box[boxIdx][num] = true;
                    board[i][j] = num + '0';
                    if (backtrack(board, i, j + 1))
                        return true;
                    board[i][j] = '.';
                    row[i][num] = col[j][num] = box[boxIdx][num] = false;
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                int num = board[i][j] - '0';
                int boxIdx = (i / 3) * 3 + j / 3;
                row[i][num] = col[j][num] = box[boxIdx][num] = true;
            }
        }
        backtrack(board, 0, 0);
    }
};