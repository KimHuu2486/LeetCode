class Solution {
public:
    void build(vector<int>& baskets, vector<int>& segTree, int v, int left,
               int right) {
        if (left == right) {
            segTree[v] = baskets[left];
        } else {
            int mid = (left + right) / 2;
            build(baskets, segTree, 2 * v, left, mid);
            build(baskets, segTree, 2 * v + 1, mid + 1, right);
            segTree[v] = max(segTree[2 * v], segTree[2 * v + 1]);
        }
    }
    void update(vector<int>& segTree, int v, int left, int right, int pos,
                int value) {
        if (left == right) {
            segTree[v] = value;
        } else {
            int mid = (left + right) / 2;
            if (pos <= mid) {
                update(segTree, 2 * v, left, mid, pos, value);
            } else {
                update(segTree, 2 * v + 1, mid + 1, right, pos, value);
            }
            segTree[v] = max(segTree[2 * v], segTree[2 * v + 1]);
        }
    }
    int findIndex(vector<int>& segTree, int v, int left, int right, int value) {
        if (segTree[v] < value)
            return -1;
        if (left == right)
            return left;
        int mid = (left + right) / 2;
        int i1 = findIndex(segTree, 2 * v, left, mid, value);
        if (i1 != -1)
            return i1;
        return findIndex(segTree, 2 * v + 1, mid + 1, right, value);
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        vector<int> segTree(4 * n);
        build(baskets, segTree, 1, 0, n - 1);
        int cnt = 0;
        for (int fruit : fruits) {
            int idx = findIndex(segTree, 1, 0, n - 1, fruit);
            if (idx == -1)
                cnt++;
            else {
                update(segTree, 1, 0, n - 1, idx, -1);
            }
        }
        return cnt;
    }
};