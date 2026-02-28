class Solution {
public:
    int concatenatedBinary(int n) {
        long long MOD = 1e9 + 7;
        long long ans = 1;
        
        for (int i = 2; i <= n; i++) {
            int cntBit = bit_width((unsigned int) i);
            ans <<= cntBit;
            ans = (ans | i) % MOD;
        }
        
        return ans;
    }
};