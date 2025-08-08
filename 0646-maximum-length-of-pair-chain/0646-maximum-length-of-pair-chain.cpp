class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        std::sort(pairs.begin(), pairs.end(),
                  [](const std::vector<int>& a, const std::vector<int>& b) {
                      return a[1] < b[1];
                  });
        int prevEnd = pairs[0][1];
        int res = 1;
        for (int i = 1; i < pairs.size(); i++) {
            if (pairs[i][0] > prevEnd) {
                res++;
                prevEnd = pairs[i][1];
            }
        }
        return res;
    }
};