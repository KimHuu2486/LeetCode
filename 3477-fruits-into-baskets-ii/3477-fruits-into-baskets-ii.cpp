class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> visited(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (fruits[i] <= baskets[j] && !visited[j]) {
                    visited[j] = true;
                    ans++;
                    break;
                }
            }
        }
        return n - ans;
    }
};