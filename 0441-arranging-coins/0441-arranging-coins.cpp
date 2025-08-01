class Solution {
public:
    int arrangeCoins(int n) {
        int cnt = 0;
        for (int i = 1; i<=n; i++){
            cnt++;
            n-=i;
        }
        return cnt;
    }
};