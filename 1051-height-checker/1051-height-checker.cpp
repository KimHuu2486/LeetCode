class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector<int>right(n);
        for (int i = 0; i<n; i++){
            right[i] = heights[i];
        }
        sort(right.begin(),right.end());
        int ans = 0;
        for (int i = 0; i<n; i++){
            if (right[i]!=heights[i]) ans++;
        }
        return ans;
    }
};