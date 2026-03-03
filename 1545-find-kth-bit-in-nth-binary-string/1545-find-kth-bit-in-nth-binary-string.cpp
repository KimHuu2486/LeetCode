class Solution {
public:
    char findKthBit(int n, int k) {
        string cur = "0";

        for (int i = 2; i <= n; i++) {
            string next = cur;
            next.push_back('1');

            int m = cur.size();
            for (int j = 0; j < m / 2; j++) {
                if (cur[j] == cur[m - 1 - j]) {
                    cur[j] = cur[m - 1 - j] = '1' - cur[j] + '0';
                }
            }
            cur[m / 2] = '1' - cur[m / 2] + '0';

            next.append(cur);

            cur = next;
        }

        return cur[k - 1];
    }
};