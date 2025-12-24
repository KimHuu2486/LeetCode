class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApple = accumulate(apple.begin(), apple.end(), 0);

        sort(capacity.begin(), capacity.end(), greater<int>());

        int cnt = 0;
        while (totalApple > 0) {
            totalApple -= capacity[cnt];
            cnt++;
        }
        return cnt;
    }
};