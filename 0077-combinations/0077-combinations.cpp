class Solution {
public:
    void FindCombination(vector<vector<int>>&ans, vector<int>&res, int index,int start, int n, int k){
        if ( k== 0){
            ans.push_back(res);
            return;
        }
        for (int i = start; i<=n - k + 1; i++){
            res[index] = i;
            FindCombination(ans, res, index+1, i+1, n, k-1);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>res(k, 0);
        FindCombination(ans, res, 0, 1, n, k);
        return ans;
    }
};