class Solution {
private:
    vector<int> parent;
    vector<int> rnk;
    int _n;

    int find(int v) {
        while (v != parent[v]) {
            parent[v] = parent[parent[v]];
            v = parent[v];
        }
        return v;
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return;

        if (a == 0 || b == 0) {
            parent[a] = 0;
            parent[b] = 0;
            return;
        }

        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }

public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {
        parent.resize(n);
        rnk.assign(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        unite(0, firstPerson);

        sort(meetings.begin(), meetings.end(),
             [](const auto& a, const auto& b) { return a[2] < b[2]; });

        int m = meetings.size();
        int left = 0;

        while (left < m) {
            int t = meetings[left][2];

            int right = left;
            while (right < m && meetings[right][2] == t)
                right++;

            vector<int> participants;
            participants.reserve(2 * (right - left));

            for (int i = left; i < right; i++) {
                int x = meetings[i][0];
                int y = meetings[i][1];
                unite(x, y);
                participants.push_back(x);
                participants.push_back(y);
            }

            sort(participants.begin(), participants.end());
            participants.erase(unique(participants.begin(), participants.end()),
                               participants.end());

            for (int p : participants) {
                if (find(p) != 0) {
                    parent[p] = p;
                    rnk[p] = 0;
                }
            }

            left = right;
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (find(i) == 0)
                ans.push_back(i);
        }
        return ans;
    }
};