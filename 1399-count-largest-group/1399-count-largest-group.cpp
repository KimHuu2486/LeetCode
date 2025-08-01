class Solution {
public:
    int countLargestGroup(int n) {
        int freq[37] = {}, maxSize = 0, count = 0;
        for (int i = 1; i <= n; i++) {
            int sum = 0, num = i;
            while (num) sum += num % 10, num /= 10;
            maxSize = max(maxSize, ++freq[sum]);
        }
        for (int i = 0; i < 37; i++) count += (freq[i] == maxSize);
        return count;
    }
};