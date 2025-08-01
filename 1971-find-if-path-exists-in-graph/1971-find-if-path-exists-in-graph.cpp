class Solution {
public:
    int find(vector<int>&parent, int v){
        if (v == parent[v] )return v;
        return parent[v] = find(parent, parent[v]);
    }
    void Union(int a, int b, vector<int>&parent, vector<int>&size){
        a = find(parent, a);
        b= find(parent, b);
        if (a!=b) {
            if (size[a] <size[b]){
                swap(a, b);
            }
            parent[b] =a;
            size[a]+=size[b];
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>parent(n+1), size(n+1);
        for (int i = 1; i<=n; i++){
            parent[i]= i;
            size[i]=1;
        }
        for (int i = 0 ; i<edges.size(); i++){
            Union(edges[i][0], edges[i][1], parent, size);
        }
        return find(parent, source) == find(parent, destination);
    }
};