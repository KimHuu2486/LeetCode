class Solution {
private:
    int n_val;
    int limit; 
    vector<int> price;
    vector<int> sell; 
    vector<vector<int>> adj; 
    
    // dp[u][0]: lợi nhuận nếu sếp của u không mua
    // dp[u][1]: lợi nhuận nếu sếp của u có mua
    vector<vector<long long>> dp_full;
    vector<vector<long long>> dp_discount;

    const long long INF = -1e18;
public:
    void merge_knapsack(vector<long long>& target, const vector<long long>& source) {
        vector<long long> next_dp(limit + 1, INF);
        
        for (int c1 = 0; c1 <= limit; ++c1) {
            if (target[c1] == INF) continue;
            
            for (int c2 = 0; c2 <= limit - c1; ++c2) {
                if (source[c2] == INF) continue;
                
                next_dp[c1 + c2] = max(next_dp[c1 + c2], target[c1] + source[c2]);
            }
        }
        target = next_dp; 
    }

    void dfs(int u) {
        vector<long long> pool_buy(limit + 1, INF);
        vector<long long> pool_skip(limit + 1, INF);
        
        pool_buy[0] = 0;
        pool_skip[0] = 0;

        for (int v : adj[u]) {
            dfs(v);
            merge_knapsack(pool_buy, dp_discount[v]);
            merge_knapsack(pool_skip, dp_full[v]);
        }

        int p_full = price[u-1];
        int p_half = floor(p_full / 2.0);
        int profit_term = sell[u-1]; 

        dp_full[u].assign(limit + 1, INF);
        dp_discount[u].assign(limit + 1, INF);

        for (int c = 0; c <= limit; ++c) {
            if (pool_buy[c] != INF && c + p_half <= limit) {
                long long profit = pool_buy[c] + (long long)profit_term - p_half;
                dp_discount[u][c + p_half] = max(dp_discount[u][c + p_half], profit);
            }
        }

        for (int c = 0; c <= limit; ++c) {
            if (pool_skip[c] != INF) {
                dp_discount[u][c] = max(dp_discount[u][c], pool_skip[c]);
            }
        }

        for (int c = 0; c <= limit; ++c) {
            if (pool_buy[c] != INF && c + p_full <= limit) {
                long long profit = pool_buy[c] + (long long)profit_term - p_full;
                dp_full[u][c + p_full] = max(dp_full[u][c + p_full], profit);
            }
        }

        for (int c = 0; c <= limit; ++c) {
            if (pool_skip[c] != INF) {
                dp_full[u][c] = max(dp_full[u][c], pool_skip[c]);
            }
        }
    }

    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        n_val = n;
        limit = budget;
        price = present;
        sell = future;
        
        adj.assign(n + 1, vector<int>());
        for (auto& edge : hierarchy) {
            adj[edge[0]].push_back(edge[1]);
        }

        dp_full.resize(n + 1);
        dp_discount.resize(n + 1);

        dfs(1);

        long long ans = 0;
        for (long long val : dp_full[1]) {
            if (val != INF) {
                ans = max(ans, val);
            }
        }

        return (int)ans;
    }
};