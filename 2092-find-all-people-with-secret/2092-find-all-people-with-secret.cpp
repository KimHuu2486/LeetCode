class Solution {
private:
    vector<int> parent;
    int _n;

    void makeSet() {
        for (int i = 0; i < _n; i++) {
            parent[i] = i;
        }
    }
    int find(int v) {
        if (v == parent[v]) {
            return v;
        }
        return parent[v] = find(parent[v]);
    }
    void Union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (a == 0) {
                parent[b] = a;
            } else
                parent[a] = b;
        }
    }

public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {
        _n = n;
        parent.resize(n);
        makeSet();
        Union(0, firstPerson);

        sort(meetings.begin(), meetings.end(),
             [](auto& a, auto& b) { return a[2] < b[2]; });

        int m = meetings.size();
        int left = 0;

        while (left < m) {
            int t = meetings[left][2];
            int right = left;

            vector<int> participants;
            participants.reserve(2 * (m - left));

            while (right < m && meetings[right][2] == t) {
                int x = meetings[right][0];
                int y = meetings[right][1];
                Union(x, y);
                participants.push_back(x);
                participants.push_back(y);
                right++;
            }

            for (int p : participants) {
                if (find(p) != 0)
                    parent[p] = p;
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