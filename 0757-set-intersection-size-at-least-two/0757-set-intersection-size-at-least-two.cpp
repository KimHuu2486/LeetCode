class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            if (a[1] == b[1]) {
                return a[0] > b[0];
            }
            return a[1] < b[1];
        });
        
        int ans = 0;
        int a = -1, b = -1;

        for (int i = 0; i < n; i++) {
            int start = intervals[i][0], end = intervals[i][1];

            bool a_in = (a >= start);
            bool b_in = (b >= start);

            if (a_in && b_in) continue;

            if (!a_in && !b_in) {
                ans+=2;
                a = end - 1;
                b = end;
            }
            else {
                ans+=1;
                a = b;
                b = end;
            }
        }
        return ans;
    }
};