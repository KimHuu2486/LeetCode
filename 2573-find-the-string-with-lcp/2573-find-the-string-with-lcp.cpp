class Solution {
public:
    class DSU {
    private:
        vector<int>parent;
        int n;
    public:
        DSU(int nTemp): n(nTemp) {
            parent.resize(n);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }    
        int find(int v) {
            if (v == parent[v]) return v;
            return parent[v] = find(parent[v]);
        }
        void Union(int a, int b) {
            a = find(a);
            b = find(b);
            if (a != b) {
                parent[b] = a;
            }
        }
    };
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        DSU dsu(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (lcp[i][j] > 0) {
                    dsu.Union(i, j);
                }
            }
        }

        string ans(n, ' ');
        char cur = 'a';
        for (int i = 0; i < n; i++) {
            int root = dsu.find(i);
            if (ans[root] == ' ') {
                if (cur > 'z') return "";
                ans[root] = cur++;
            }
            ans[i] = ans[root];
        }

        vector<vector<int>> check(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (ans[i] == ans[j]) {
                    check[i][j] = check[i + 1][j + 1] + 1;
                } else {
                    check[i][j] = 0;
                }
                
                if (check[i][j] != lcp[i][j]) return "";
            }
        }

        return ans;
    }
};