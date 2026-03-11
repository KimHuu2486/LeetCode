class Solution {
public:
    int bitwiseComplement(int n) {
        long long sum = 1;
        while (sum < n) {
            sum <<= 1;
            sum += 1;
        }
        return sum - n;
    }
};