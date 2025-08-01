class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int>q;
        int n = arr.size();
        q.push(start);
        vector<bool>visited(n, 0);
        while (!q.empty()){
            int cur = q.front();
            visited[cur] = true;
            q.pop();
            if (arr[cur] == 0) return true;
            if (arr[cur] + cur < n && !visited[arr[cur] + cur]) q.push(cur+ arr[cur]);
            if (cur - arr[cur] >=0 && !visited[cur - arr[cur]]) q.push(cur - arr[cur]);
        }
        return 0;
    }
};