class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child = 0, cookie = 0;
        while (child<g.size() && cookie<s.size()){
            if (g[child]<=s[cookie]){
                count++;
                child++;
                cookie++;
            }
            else {
                cookie++;
            }
        }
        return count;
    }
};