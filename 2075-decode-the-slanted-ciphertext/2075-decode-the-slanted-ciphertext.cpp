class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size() / rows, m = rows;
        string originalText;
        
        for (int c = 0; c < n; ++c) {
            for (int i = 0, j = c; i < rows && j < n; ++i, ++j) {
                int index = i * n + j;
                originalText += encodedText[index];
            }
        }

        while (!originalText.empty() && isspace(originalText.back())) {
            originalText.pop_back();
        }

        return originalText;
    }
};