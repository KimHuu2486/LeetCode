class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>degree(numCourses, 0);
        for (int i = 0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            degree[prerequisites[i][0]]++;
        }
        queue<int>q;
        for (int i = 0; i<numCourses; i++){
            if (degree[i] == 0){
                q.push(i);
            }
        }
        int cnt = 0;
        while (!q.empty()){
            int cur = q.front();
            q.pop();
            cnt++;
            for (int i : adj[cur]){
                degree[i]--;
                if (degree[i] == 0){
                    q.push(i);
                }
            }
        }
        return cnt == numCourses;
    }
};