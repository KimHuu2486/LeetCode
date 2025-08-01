class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> index;
        heights.push_back(0);
        int res = 0;
        for (int i = 0 ; i<heights.size(); i++){
            while (!index.empty() && heights[index.top()] >= heights[i]){
                int h = heights[index.top()];
                index.pop();
                int w = index.empty()?-1:index.top();
                res = max(res, h * (i - w - 1));
            }
            index.push(i);
        }
        return res;
    }
};