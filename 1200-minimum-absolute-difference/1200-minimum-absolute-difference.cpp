class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        vector<vector<int>> ans;
        for (int i = 0; i < n - 1; i++) {
            int curDiff = arr[i + 1] - arr[i];
            if (curDiff <= minDiff) {
                if (curDiff < minDiff) {
                    ans.clear();
                    minDiff = curDiff;
                }
                ans.push_back({arr[i], arr[i + 1]});
            }
        }
        return ans;
    }
};