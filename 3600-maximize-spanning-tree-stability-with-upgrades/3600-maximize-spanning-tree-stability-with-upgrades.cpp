class DSU {
private:
    vector<int> parents;
public:
    int components;
    DSU(int n) {
        parents.resize(n);
        iota(parents.begin(), parents.end(), 0);
        components = n;
    }
    int find(int i) {
        if (parents[i] == i) return i;
        return parents[i] = find(parents[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parents[root_i] = root_j;
            components--;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    bool check(int target, int n, const vector<vector<int>>& edges, int k) {
        DSU dsu(n);
        int upgraded = 0;
        int edges_in_tree = 0;

        for (const auto& e: edges) {
            if (e[3] == 1) {
                if (e[2] < target) return false;
                if (!dsu.unite(e[0], e[1])) {
                    return false; 
                }
                edges_in_tree++;
            }
        }

        for (const auto& e: edges) {
            if (e[3] == 0 && e[2] >= target) {
                if (dsu.unite(e[0], e[1])) {
                    edges_in_tree++;
                }
            }
        }

        for (const auto& e: edges) {
            if (e[3] == 0 && e[2] < target && (2 * e[2] >= target)) {
                if (dsu.find(e[1]) != dsu.find(e[0])) {
                    if (upgraded < k) {
                        dsu.unite(e[0], e[1]);
                        upgraded++;
                        edges_in_tree++;
                    }
                }
            }
        }

        return (edges_in_tree == n - 1 && dsu.components == 1);
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int max_weights = 0;
        for (const auto& e:edges) {
            if (e[3] == 1) {
                max_weights = max(max_weights, e[2]);
            }
            else {
                max_weights = max(max_weights, e[2] * 2);
            }
        }

        int low = 0, high = max_weights;
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid, n, edges, k)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};