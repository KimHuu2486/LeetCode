class Solution {
public:
    int countSetBits(int num) {
        int ans = 0;
        while (num) {
            ans += (num & 1);
            num >>= 1;
        }
        return ans;
    }
    int countPrimeSetBits(int left, int right) {
        vector<bool> isPrime(21, false);
        isPrime[2] = isPrime[3] = isPrime[5] = isPrime[5] = isPrime[7] =
            isPrime[11] = isPrime[13] = isPrime[17] = isPrime[19] = true;
        int ans = 0;
        for (int i = left; i <= right; i++) {
            int bits = countSetBits(i);
            if (isPrime[bits]) {
                ans++;
            }
        }
        return ans;
    }
};