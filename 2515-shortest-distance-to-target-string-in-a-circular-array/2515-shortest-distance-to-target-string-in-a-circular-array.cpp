class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();

        auto minDistance = [&n](int cur, int des) {
            int temp = abs(cur - des);
            return min(temp, n - temp);
        };

        int ans = INT_MAX;
        vector<int> idx;
        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                ans = min(ans, minDistance(startIndex, i));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};