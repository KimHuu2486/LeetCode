class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        long long maxDiagSq = -1; 
        int maxArea = -1;

        for (auto &cur : dimensions) {
            long long curDiagSq = 1LL * cur[0] * cur[0] + 1LL * cur[1] * cur[1];
            int curArea = cur[0] * cur[1];

            if (curDiagSq > maxDiagSq) {
                maxDiagSq = curDiagSq;
                maxArea = curArea;
            } 
            else if (curDiagSq == maxDiagSq) {
                maxArea = max(maxArea, curArea);
            }
        }
        return maxArea;
    }
};
