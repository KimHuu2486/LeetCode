class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        vector<bool>isLexi(n, false);

        int cnt =  0;
        for (int j = 0; j < m; j++) {
            unordered_set<int>idxLexi;
            for (int i = 1; i < n; i++) {
                if (isLexi[i] == true) {
                    continue;
                }
                if (strs[i - 1][j] < strs[i][j]) {
                    isLexi[i] = true;
                    idxLexi.insert(i);
                }
                else if (strs[i - 1][j] > strs[i][j]) {
                    for (int idx : idxLexi) {
                        isLexi[idx] = false;
                    }
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};