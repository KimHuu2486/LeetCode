class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> ans(n, 0LL);
        for (int i = 0; i < n; i++) {
            if (ans[i] == 0) {
                vector<int> idx = mp[nums[i]];
                int m = idx.size();
                if (m == 1) {
                    continue;
                }
                vector<long long> prefix(m);
                prefix[0] = idx[0];
                for (int j = 1; j < m; j++) {
                    prefix[j] = prefix[j - 1] + idx[j];
                }

                for (int j = 0; j < m; j++) {
                    if (j == 0) {
                        ans[idx[j]] = prefix[m - 1] - 1LL * idx[j] * m;
                    } else if (j == m - 1) {
                        ans[idx[j]] = 1LL * idx[j] * (m - 1) - prefix[j - 1];
                    } else {
                        long long right =
                            prefix[m - 1] - prefix[j] - 1LL * (m - j - 1) * idx[j];
                        long long left = 1LL * j * idx[j] - prefix[j - 1];
                        ans[idx[j]] = right + left;
                    }
                }
            }
        }

        return ans;
    }
};