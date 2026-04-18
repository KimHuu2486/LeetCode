class Solution {
public:
    int mirrorDistance(int n) {
        long long reverse = 0, temp = n;
        while (temp > 0) {
            reverse = reverse * 10 + temp % 10;
            temp /= 10;
        }

        return abs(n - reverse);
    }
};