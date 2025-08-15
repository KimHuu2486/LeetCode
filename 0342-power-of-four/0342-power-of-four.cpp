class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n<= 0 || (n & (n-1)) != 0) return false;
        int temp = sqrt(n);
        return temp*temp == n;
    }
};