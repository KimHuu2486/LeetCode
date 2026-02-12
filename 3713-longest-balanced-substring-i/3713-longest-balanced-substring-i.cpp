class Solution {
public:
    bool check(const vector<int>& freq) {
        int val = 0;

        for (const int& cur: freq) {
            if (val == 0) {
                val = cur;
            }
            else {
                if (cur == 0) {
                    continue;
                }
                else {
                    if (val != cur) {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    int longestBalanced(string s) {
        int n = s.size();
        int ans = 1;
        for (int i = 0; i < n - 1; i++) {
            vector<int>freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                if (j - i + 1 > ans) {
                    if (check(freq)) {
                        ans = j - i + 1;
                    }
                }
            }
        }

        return ans;
    }
};