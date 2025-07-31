class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 3 || n==1) {
            return 1;
        }
        if (n%3!=0 || n<3){
            return 0;
        }
        n/=3;
        return isPowerOfThree(n);
    }
};