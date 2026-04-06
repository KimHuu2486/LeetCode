class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<long long> obs;
        for (auto &arr : obstacles) {
            obs.insert(((long long)arr[0] + 30000) * 60001 + (arr[1] + 30000));
        }

        // Bắc (0), Đông (1), Nam (2), Tây (3)
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        int x = 0, y = 0, dir = 0;
        int maxDist = 0;

        for (int curr : commands) {
            if (curr == -1) {
                dir = (dir + 1) % 4;
            } else if (curr == -2) {
                dir = (dir + 3) % 4;
            } else {
                for (int j = 0; j < curr; j++) {
                    int nextX = x + dx[dir];
                    int nextY = y + dy[dir];
                    
                    long long key = ((long long)nextX + 30000) * 60001 + (nextY + 30000);
                    if (obs.count(key)) break;
                    
                    x = nextX;
                    y = nextY;
                    maxDist = max(maxDist, x * x + y * y);
                }
            }
        }

        return maxDist;
    }
};