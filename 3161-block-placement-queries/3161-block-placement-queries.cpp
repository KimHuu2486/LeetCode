class Solution {
public:
    const int MAX = 5e4;
    vector<int> tree;
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        }
        else {
            update(2 * node + 1,  mid + 1, end, idx, val);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    int queryTree(int node, int start, int end, int L, int R) {
        if (R < start || end < L) return 0;
        if (L <= start && end <= R) return tree[node];

        int mid = start +  (end - start) / 2;
        int p1 = queryTree(2 * node, start, mid, L, R);
        int p2 = queryTree(2 * node + 1, mid + 1, end, L, R);
        return max(p1, p2);
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        tree.assign(4 * MAX, 0);

        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(MAX + 1); 

        update(1, 0, MAX, MAX + 1, MAX + 1);

        vector<bool> results;

        for (const auto& q : queries) {
            int type = q[0];
            if (type == 1) {
                int x = q[1];
                
                auto it = obstacles.upper_bound(x);
                int next_obs = *it;
                int prev_obs = *prev(it);

                obstacles.insert(x);

                update(1, 0, MAX, x, x - prev_obs);
                if (next_obs <= MAX) {
                    update(1, 0, MAX, next_obs, next_obs - x);
                }

            } else if (type == 2) {
                int x = q[1];
                int sz = q[2];

                auto it = obstacles.upper_bound(x);
                int prev_obs = *prev(it);

                int max_gap = queryTree(1, 0, MAX, 0, prev_obs);

                max_gap = max(max_gap, x - prev_obs);

                results.push_back(max_gap >= sz);
            }
        }

        return results;
    }
};