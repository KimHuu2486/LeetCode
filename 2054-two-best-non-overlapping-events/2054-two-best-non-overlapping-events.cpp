class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        vector<vector<int>> start_event = events;
        vector<vector<int>> end_event = events;

        sort(start_event.begin(), start_event.end(),
             [](auto& a, auto& b) { return a[0] < b[0]; });

        sort(end_event.begin(), end_event.end(),
             [](auto& a, auto& b) { return a[1] < b[1]; });

        int end_ptr = 0;
        int max_val_end_ptr = 0;
        int ans = 0;

        for (auto& event : start_event) {
            int val = event[2];
            int start = event[0];

            while (end_ptr < n && end_event[end_ptr][1] < start) {
                max_val_end_ptr = max(max_val_end_ptr, end_event[end_ptr][2]);
                end_ptr++;
            }

            ans = max(ans, val + max_val_end_ptr);
        }

        return ans;
    }
};