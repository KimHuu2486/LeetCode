class Solution {
public:
    int countCollisions(string directions) {
        int left = 0, right = directions.size() - 1;
        bool seen_S = false;
        while (left <= right) {
            if (directions[left] == 'L' && !seen_S) {
                left++;
                continue;
            } 
            else if (directions[left] == 'S') {
                seen_S = true;
                left++;
                continue;
            }
            break;
        }
        seen_S = false;
        while (right >= left) {
            if (directions[right] == 'R' && !seen_S) {
                right--;
                continue;
            }
            else if (directions[right] == 'S') {
                seen_S = true;
                right--;
                continue;
            }
            break;
        }
        int cnt = 0;
        for (int i = left; i <= right; i++) {
            if (directions[i] == 'S') {
                continue;
            }
            cnt++;
        }
        return cnt;
    }
};