class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int nextMask[26 * 26] = {0};

        for (auto &s : allowed) {
            int a = s[0] - 'A';
            int b = s[1] - 'A';
            int c = s[2] - 'A';
            nextMask[a * 26 + b] |= (1 << c);
        }

        unordered_map<string, char> memo;

        function<bool(const string&)> can = [&](const string& row) -> bool {
            if (row.size() == 1) return true;
            if (auto it = memo.find(row); it != memo.end()) return it->second;

            int m = (int)row.size();

            for (int i = 0; i < m - 1; i++) {
                int id = (row[i] - 'A') * 26 + (row[i + 1] - 'A');
                if (nextMask[id] == 0) {
                    memo[row] = 0;
                    return false;
                }
            }

            string next(m - 1, '?');

            function<bool(int)> build = [&](int i) -> bool {
                if (i == m - 1) return can(next);

                int id = (row[i] - 'A') * 26 + (row[i + 1] - 'A');
                int mask = nextMask[id];

                while (mask) {
                    int bit = mask & -mask;
                    int c = __builtin_ctz(mask);
                    next[i] = char('A' + c);
                    if (build(i + 1)) return true;
                    mask ^= bit;
                }
                return false;
            };

            bool ans = build(0);
            memo[row] = ans ? 1 : 0;
            return ans;
        };

        return can(bottom);
    }
};
