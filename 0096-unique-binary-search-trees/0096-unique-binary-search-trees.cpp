class Solution {
public:
    int numTrees(int n) {
        vector<int>uniTree(n+1, 1);
        for (int nodes = 2; nodes<=n; nodes++){
            int total = 0;
            for (int root = 1; root<=nodes; root++){
                total+=uniTree[root-1]*uniTree[nodes -root];
            }
            uniTree[nodes] = total;
        }
        return uniTree[n];

    }
};