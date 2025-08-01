class Solution {
public:
    const int MOD = 1e9 + 7;
    long long power(long long base, long long exp){
        long long res = 1;
        while (exp>0){
            if (exp%2 == 1){
                res = res*base%MOD;
            }
            base=base*base%MOD;
            exp/=2;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;
        return power(5, even) * power(4,odd) % MOD;
    }
};