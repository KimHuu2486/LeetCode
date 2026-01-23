class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        vector<long long> val(n);
        for (int i = 0; i < n; i++) {
            val[i] = 1LL * nums[i];
        }
        vector<int> prev(n), next(n);
        vector<bool> alive(n, true);
        for (int i = 0; i < n; i++) {
            prev[i] = i - 1;
            next[i] = (i < n - 1 ? i + 1 : -1);
        }

        auto isBad = [&](int i, int j) -> bool {
            return (i != -1 && j != -1 && alive[i] && alive[j] &&
                    val[i] > val[j]);
        };

        long long bad = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] < nums[i]) {
                bad++;
            }
        }

        struct Item {
            long long sum;
            int left;
            int right;
        };

        auto cmp = [](const Item& a, const Item& b) {
            if (a.sum != b.sum)
                return a.sum > b.sum;
            return a.left > b.left;
        };

        priority_queue<Item, vector<Item>, decltype(cmp)> pq;
        for (int i = 0; i < n - 1; i++) {
            pq.push({val[i] + val[i + 1], i, i + 1});
        }

        auto pushPair = [&](int i) {
            int j = (i == -1 ? -1 : next[i]);
            if (i != -1 && j != -1 && alive[i] && alive[j]) {
                pq.push({val[i] + val[j], i, j});
            }
        };

        int ops = 0;
        while (bad > 0) {
            Item cur;
            while (true) {
                cur = pq.top();
                pq.pop();
                int i = cur.left, j = cur.right;
                if (!alive[i] || !alive[j])
                    continue;
                if (next[i] != j)
                    continue;

                long long realSum = val[i] + val[j];
                if (realSum != cur.sum) {
                    pq.push({realSum, i, j});
                    continue;
                }

                break;
            }

            int i = cur.left, j = cur.right;
            int a = prev[i], b = next[j];

            if (isBad(a, i))
                bad--;
            if (isBad(i, j))
                bad--;
            if (isBad(j, b))
                bad--;

            val[i] = cur.sum;
            alive[j] = false;

            next[i] = b;
            if (b != -1)
                prev[b] = i;

            if (isBad(a, i))
                bad++;
            if (isBad(i, b))
                bad++;

            pushPair(a);
            pushPair(i);

            ops++;
        }

        return ops;
    }
};