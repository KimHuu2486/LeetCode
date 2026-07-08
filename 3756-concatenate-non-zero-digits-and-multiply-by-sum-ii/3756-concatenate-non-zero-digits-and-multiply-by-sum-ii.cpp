class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1e9 + 7;
        int n = s.size();
        
        vector<int> prefixSum(n + 1, 0);
        vector<long long> prefixVal(n + 1, 0); 
        vector<int> prefixLen(n + 1, 0);       

        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                prefixSum[i + 1] = prefixSum[i]; 
                prefixVal[i + 1] = prefixVal[i]; 
                prefixLen[i + 1] = prefixLen[i];
            } else {
                int digit = s[i] - '0';
                prefixSum[i + 1] = prefixSum[i] + digit; 
                prefixVal[i + 1] = (prefixVal[i] * 10 + digit) % MOD;
                prefixLen[i + 1] = prefixLen[i] + 1;
            }
        }

        int m = queries.size();
        vector<int> ans(m);
        
        for (int i = 0; i < m; i++) {
            int a = queries[i][0], b = queries[i][1] + 1;
            
            long long sum = prefixSum[b] - prefixSum[a];

            int len_a = prefixLen[a];
            int len_b = prefixLen[b];
            int length_diff = len_b - len_a;

            if (length_diff == 0) {
                ans[i] = 0;
                continue;
            }

            long long result_num = (prefixVal[b] - (prefixVal[a] * pow10[length_diff]) % MOD + MOD) % MOD;
            
            ans[i] = (result_num * sum) % MOD;
        }

        return ans;
    }
};