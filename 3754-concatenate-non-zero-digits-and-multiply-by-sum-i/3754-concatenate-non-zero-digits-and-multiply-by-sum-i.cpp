class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sumDigit = 0;
        long long x = 0;
        long long placeValue = 1; 

        while (n > 0) {
            int cur = n % 10;
            if (cur != 0) {
                sumDigit += cur;
                
                x = cur * placeValue + x; 
                placeValue *= 10;
            }
            n /= 10;
        }

        return x * sumDigit;
    }
};