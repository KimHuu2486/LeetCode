class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int>freq(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>heapq;
        for (int i = 0; i < n; i++) {
            heapq.push({0LL, i});
        }
        sort(meetings.begin(), meetings.end());

        for (int i = 0; i < meetings.size(); i++) {
            int start = meetings[i][0];
            int end = meetings[i][1];
            auto cur = heapq.top();
            heapq.pop();

            if (cur.first < start) {
                heapq.push({start, cur.second});
                i--;
            }
            else {
                freq[cur.second]++;
                heapq.push({cur.first + (end - start), cur.second});
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (freq[i] > freq[ans]) {
                ans = i;
            }
        }
        return ans;
    }
};