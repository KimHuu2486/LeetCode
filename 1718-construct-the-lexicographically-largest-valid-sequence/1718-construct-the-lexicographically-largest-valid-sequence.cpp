class Solution {
public:
    bool backtrack(vector<int>&ans, vector<bool>&used, int index, int n){
        while (index<ans.size() && ans[index]!= 0){
            index++;
        }
        if (index == ans.size()) return true;
        for (int i = n; i>=1; i--){
            if (used[i]) continue;
            if (i == 1){
                ans[index] = 1;
                used[1] = 1;
                if (backtrack(ans,used, index + 1, n)) return true;
                ans[index] = 0;
                used[1] = 0;
            }
            else if (index+i<ans.size() && ans[index+i] == 0){
                ans[index] = i;
                ans[index+i] = i;
                used[i] = 1;
                if (backtrack(ans, used, index+1, n)) return true;
                ans[index] = 0;
                ans[index+i] = 0;
                used[i] = 0;
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int>ans(2*n - 1, 0);
        vector<bool>used(n+1, 0);
        backtrack(ans, used, 0, n);
        return ans;
    }
};