class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size() / rows, m = rows;
        vector<vector<char>> matrix(m, vector<char>(n));

        int cur = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = encodedText[cur];
                cur++;
            }
        }

        string originalText = "";
        for (int j = 0; j < n; j++) {
            int r = 0, c = j;
            while (r < m && c < n) {
                originalText.push_back(matrix[r][c]);
                r++;
                c++;
            }
        }

        while (!originalText.empty() && isspace(originalText.back())) {
            originalText.pop_back();
        }

        return originalText;
    }
};