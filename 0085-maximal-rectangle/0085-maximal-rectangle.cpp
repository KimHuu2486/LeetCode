class Solution {
public:
    int LargestHistogram(vector<int> height) {
        stack<int> s;
        int Max = 0;
        height.push_back(0);
        for (int i = 0; i < height.size(); i++) {
            while (!s.empty() && height[s.top()] > height[i]) {
                int h = height[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                Max = max(Max, h * width);
            }
            s.push(i);
        }
        return Max;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int ans = 0;
        vector<int> height(cols, 0);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                height[j] = (matrix[i][j] == '1') ? height[j] + 1 : 0;
            }
            ans = max(ans, LargestHistogram(height));
        }
        return ans;
    }
};