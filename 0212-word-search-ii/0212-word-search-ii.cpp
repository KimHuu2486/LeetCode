class Solution {
private:
    struct Node {
        Node* child[26];
        string word;
        bool isEnd = false;
        Node() { fill(child, child + 26, nullptr); }
    };
    Node* root = new Node();
    void insert(const string& s) {
        Node* node = root;
        for (char c : s) {
            int k = c - 'a';
            if (!node->child[k])
                node->child[k] = new Node();
            node = node->child[k];
        }
        node->isEnd = true;
        node->word = s;
    }
    void dfs(vector<vector<char>>& board, vector<string>& ans, int i, int j,
             Node* node) {
        int m = board.size(), n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '*')
            return;
        char c = board[i][j];
        int k = c - 'a';
        if (!node->child[k])
            return;
        node = node->child[k];
        if (node->isEnd) {
            ans.push_back(node->word);
            node->isEnd = false;
        }
        board[i][j] = '*';
        dfs(board, ans, i + 1, j, node);
        dfs(board, ans, i - 1, j, node);
        dfs(board, ans, i, j + 1, node);
        dfs(board, ans, i, j - 1, node);
        board[i][j] = c;
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        for (const string& s : words) {
            insert(s);
        }
        int m = board.size(), n = board[0].size();
        vector<string> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, ans, i, j, root);
            }
        }

        return ans;
    }
};