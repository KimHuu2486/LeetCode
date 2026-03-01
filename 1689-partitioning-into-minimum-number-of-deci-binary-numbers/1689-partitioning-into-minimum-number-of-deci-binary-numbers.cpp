class Solution {
public:
    int minPartitions(string n) {
        char ans = 0;
        for (char& c: n) {
            if (ans < c - '0') {
                ans = c - '0';
            }
        }
        return ans;
    }
};