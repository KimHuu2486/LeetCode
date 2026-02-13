class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 1;

        // Case 1: substring has one character
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                cnt++;
            } else {
                cnt = 1;
            }
            ans = max(ans, cnt);
        }

        // Case 2: substring has two character
        auto solve2 =
            [&](char x, char y) {
                unordered_map<int, int> mp;
                mp[0] = -1;
                int sum = 0;
                int best = 0;

                for (int i = 0; i < n; i++) {
                    if (s[i] == x)
                        sum++;
                    else if (s[i] == y)
                        sum--;
                    else {
                        sum = 0;
                        mp.clear();
                        mp[0] = i;
                        continue;
                    }
                    if (mp.count(sum)) {
                        best = max(best, i - mp[sum]);
                    } else {
                        mp[sum] = i;
                    }
                }

                return best;
            };

        ans = max({ans, solve2('a', 'b'), solve2('a', 'c'), solve2('b', 'c')});

        // Case 3: substring has three character
        map<pair<int, int>, int> mp;
        mp[{0, 0}] = -1;
        int ca = 0, cb = 0, cc = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')
                ca++;
            else if (s[i] == 'b')
                cb++;
            else
                cc++;

            int x = ca - cb, y = cc - cb;

            pair<int, int> key = {x, y};

            if (mp.count(key)) {
                ans = max(ans, i - mp[key]);
            } else {
                mp[key] = i;
            }
        }

        return ans;
    }
};