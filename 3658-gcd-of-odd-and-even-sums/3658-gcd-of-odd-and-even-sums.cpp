class Solution {
public:
    int GCD(int a, int b) {
        if (a < b) {
            swap(a, b);
        }
        if (a % b == 0) return b;
        return GCD(b, a % b);
    }
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 1;
        int cur = 1;
        for (int i = 1; i < n; i++) {
            cur += 2;
            sumOdd += cur;
        }

        int sumEven = sumOdd + n;
        return GCD(sumEven, sumOdd);
    }
};