class Solution {
public:
    int minOperations(string s) {
        int beginOne = 0, beginZero = 0;
        int curOne = 1;
        for (const char& c : s) {
            int cur = c - '0';
            if (cur == curOne) {
                beginZero++;
            } else {
                beginOne++;
            }
            curOne = 1 - curOne;
        }
        return min(beginOne, beginZero);
    }
};