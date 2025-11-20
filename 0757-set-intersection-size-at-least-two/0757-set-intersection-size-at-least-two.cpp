class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size();
        unordered_set<int>ans;
        vector<int>count(n);
        sort(intervals.begin(), intervals.end(), [](auto a, auto b) {
            if (a[1] == b[1]) {
                return a[0] < b[0];
            }
            return a[1] < b[1];
        });

        int start = 0;
        while (start < n) {
            int val = intervals[start][1];
            if (ans.find(val) != ans.end()) {
                val--;
            }
            for (int i = start; i <n ; i++) {
                if (intervals[i][0] <= val && val <= intervals[i][1]) {
                    count[i]++;
                    if (count[i] >= 2) {
                        start++;
                    }
                }
                else 
                    break;
            }
            ans.insert(val);
        }
        return ans.size();
    }
};