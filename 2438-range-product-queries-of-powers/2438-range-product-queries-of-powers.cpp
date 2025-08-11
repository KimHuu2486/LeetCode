class Solution {
private:
    long long modulo = 1e9 + 7;
    vector<long long> segmentTree;

public:
    void build(vector<long long>& powers, int v, int left, int right) {
        if (left == right) {
            segmentTree[v] = powers[left];
        } else {
            int mid = (left + right) / 2;
            build(powers, 2 * v, left, mid);
            build(powers, 2 * v + 1, mid + 1, right);
            segmentTree[v] =
                (segmentTree[2 * v] * segmentTree[2 * v + 1]) % modulo;
        }
    }
    int product(int v, int tl, int tr, int left, int right) {
        if (left > right)
            return 1;
        if (tl == left && tr == right)
            return segmentTree[v];
        int tm = (tl + tr) / 2;
        long long s1 = product(2 * v, tl, tm, left, min(tm, right));
        long long s2 = product(2 * v + 1, tm + 1, tr, max(left, tm + 1), right);
        return (s1 * s2) % modulo;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        long long temp = 1;
        vector<long long> powers;
        while (n > 0) {
            if (n % 2 != 0) {
                powers.push_back(temp);
            }
            temp *= 2;
            n /= 2;
        }

        segmentTree.resize(powers.size() * 4);
        build(powers, 1, 0, powers.size() - 1);

        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            ans[i] =
                product(1, 0, powers.size() - 1, queries[i][0], queries[i][1]);
        }
        return ans;
    }
};