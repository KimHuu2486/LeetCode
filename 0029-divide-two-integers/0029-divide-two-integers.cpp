class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MAX && divisor == -1) return INT_MIN+1;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;
        if (dividend == INT_MAX && divisor == 1) return INT_MAX;
        int count = 0;
        bool isPositive = (dividend<0 == divisor<0); 

        long long absdividend = abs((long long)dividend);
        long long absdivisor = abs((long long)divisor);
        while (absdividend>=absdivisor){
            short q = 0;
            while (absdividend>(absdivisor<<(q+1))) q++;
            count+=(1<<q);
            absdividend = absdividend-(absdivisor<<q);
        }
        if (!isPositive){
            return 0-count;
        }
        return count;
    }
};