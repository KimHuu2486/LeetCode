class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k == 2 || k == 5) return -1;

        int rem = 0;
        int len = 0;
        vector<bool>visited(k, false);
        while (true) {
            rem = (rem * 10 + 1) % k;
            if (visited[rem]) return - 1;
            visited[rem] = true;
            len++;
            if (rem == 0) return len;
        }
        return -1;
    }
};