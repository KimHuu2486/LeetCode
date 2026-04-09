class Solution {
    const int MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = 200; 
        
        vector<vector<pair<int, pair<int, int>>>> lightQueries(B);
        
        for (const auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            
            if (k >= B) {
                for (int idx = l; idx <= r; idx += k) {
                    nums[idx] = (1LL * nums[idx] * v) % MOD;
                }
            } else {
                lightQueries[k].push_back({l, {r, v}});
            }
        }
        
        for (int k = 1; k < B; ++k) {
            if (lightQueries[k].empty()) continue;
            
            vector<int> diff(n, 1);
            for (const auto& q : lightQueries[k]) {
                int l = q.first;
                int r = q.second.first;
                int v = q.second.second;
                
                diff[l] = (1LL * diff[l] * v) % MOD;
                
                int count = (r - l) / k + 1;
                int next_idx = l + count * k;

                if (next_idx < n) {
                    diff[next_idx] = (1LL * diff[next_idx] * modInverse(v)) % MOD;
                }
            }
            
            for (int i = 0; i < n; ++i) {
                if (i >= k) {
                    diff[i] = (1LL * diff[i] * diff[i - k]) % MOD;
                }
                if (diff[i] != 1) {
                    nums[i] = (1LL * nums[i] * diff[i]) % MOD;
                }
            }
        }
        
        int result = 0;
        for (int val : nums) {
            result ^= val;
        }
        
        return result;
    }
};