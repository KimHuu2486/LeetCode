class Solution {
public:
    int histogramSquare(vector<int> vec) {
        vec.push_back(0);
        stack<int> s;
        int square = 0;
        for (int i = 0; i < vec.size(); i++) {
            while (!s.empty() && vec[s.top()] > vec[i]) {
                int height = vec[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                int temp = pow(min(height, width), 2);
                square = max(square, temp);
            }
            s.push(i);
        }
        return square;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxSquare = 0;
        vector<int> vec(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vec[j] = (matrix[i][j] == '1') ? (vec[j] + 1) : 0;
            }
            maxSquare = max(maxSquare, histogramSquare(vec));
        }
        return maxSquare;
    }
};