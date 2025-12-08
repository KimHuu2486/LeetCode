class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n ; j++) {
                int c2 = i * i + j * j;
                int c = sqrt(c2);
                if (c * c == c2 && c <= n) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};