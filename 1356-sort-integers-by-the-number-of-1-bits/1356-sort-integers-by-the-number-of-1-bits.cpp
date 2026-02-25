class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int& a, int& b) {
            int n1 = __builtin_popcount(a), n2 = __builtin_popcount(b);
            if (n1 == n2) {
                return a < b;
            }
            return n1 < n2;
        });
        return arr;
    }
};