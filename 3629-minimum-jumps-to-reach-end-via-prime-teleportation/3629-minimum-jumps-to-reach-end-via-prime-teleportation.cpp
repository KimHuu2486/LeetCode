class Solution {
public:
    bool isPrime(int n) {
        if (n < 2)
            return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    int minJumps(vector<int>& nums) {
        unordered_map<int, vector<int>> adj;
        unordered_set<int> primes_in_array;
        int n = nums.size();

        // 1. Các số nguyên tố xuất hiện trong mảng
        for (int i = 0; i < n; i++) {
            if (isPrime(nums[i])) {
                primes_in_array.insert(nums[i]);
            }
        }

        // 2. Phân tích thừa số nguyên tố, xây dựng danh sách kề
        for (int i = 0; i < n; i++) {
            int val = nums[i];

            if (val % 2 == 0) {
                if (primes_in_array.find(2) != primes_in_array.end()) {
                    adj[2].push_back(i);
                }
                while (val % 2 == 0) {
                    val /= 2;
                }
            }

            for (int factor = 3; factor * factor <= val; factor += 2) {
                if (val % factor == 0) {
                    if (primes_in_array.find(factor) != primes_in_array.end()) {
                        adj[factor].push_back(i);
                    }
                    while (val % factor == 0) {
                        val /= factor;
                    }
                }
            }

            if (val > 1) {
                if (primes_in_array.find(val) != primes_in_array.end()) {
                    adj[val].push_back(i);
                }
            }
        }

        // 3. BFS
        queue<pair<int, int>> q;
        vector<bool> visited(n, false);
        unordered_set<int> visited_primes;

        q.push({0, 0});
        visited[0] = true;

        while (!q.empty()) {
            auto [curr, jumps] = q.front();
            q.pop();

            if (curr == n - 1) {
                return jumps;
            }

            int next_forward = curr + 1;
            int next_backward = curr - 1;

            if (next_forward < n && !visited[next_forward]) {
                visited[next_forward] = true;
                q.push({next_forward, jumps + 1});
            }
            if (next_backward >= 0 && !visited[next_backward]) {
                visited[next_backward] = true;
                q.push({next_backward, jumps + 1});
            }

            int p = nums[curr];
            if (primes_in_array.find(p) != primes_in_array.end() &&
                visited_primes.find(p) == visited_primes.end()) {
                visited_primes.insert(p);

                for (int next_idx : adj[p]) {
                    if (!visited[next_idx]) {
                        visited[next_idx] = true;
                        q.push({next_idx, jumps + 1});
                    }
                }
            }
        }

        return 0;
    }
};