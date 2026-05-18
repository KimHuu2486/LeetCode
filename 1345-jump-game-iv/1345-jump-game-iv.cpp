class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<pair<int, int>> q;
        vector<bool> visited(n, false);
        q.push({0, 0});
        visited[0] = true;

        while (!q.empty()) {
            auto [idx, step] = q.front();
            q.pop();

            if (idx == n - 1) {
                return step;
            }

            if (idx - 1 >= 0 && !visited[idx - 1]) {
                q.push({idx - 1, step + 1});
                visited[idx - 1] = true;
            }
            if (idx + 1 < n && !visited[idx + 1]) {
                q.push({idx + 1, step + 1});
                visited[idx + 1] = true;
            }

            if (mp.count(arr[idx])) {
                for (int& nidx : mp[arr[idx]]) {
                    if (!visited[nidx]) {
                        q.push({nidx, step + 1});
                        visited[nidx] = true;
                    }
                }
                mp.erase(arr[idx]);
            }
        }
        return true;
    }
};