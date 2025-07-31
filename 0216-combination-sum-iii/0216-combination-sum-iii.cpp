class Solution {
public:
    void FindNum(vector<vector<int>>& ans, vector<int>& res, int tempSum,
                 int start, int index, int k, int n) {
        if (k == 1) {
            if (n - tempSum > res[index - 1] && n - tempSum < 10) {
                res[index] = n - tempSum;
                ans.push_back(res);
                return;
            }
            return;
        }
        for (int i = start; i <= 9; i++) {
            res[index] = i;
            tempSum += i;
            if (tempSum < n) {
                FindNum(ans, res, tempSum, i + 1, index + 1, k - 1, n);
            }
            tempSum-=i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if (n > k * 9 || n < k)
            return {};
        vector<vector<int>> ans;
        vector<int> res(k, 0);
        FindNum(ans, res, 0, 1, 0, k, n);
        return ans;
    }
};