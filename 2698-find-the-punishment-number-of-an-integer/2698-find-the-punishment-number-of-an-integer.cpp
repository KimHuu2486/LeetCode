class Solution {
public:
    bool partition(int x, int target){
        if (x == target) return 1;
        if (x < target || target < 0) return 0;
        const int end = min(x, 1000);
        for (int i = 10; i<=end; i*=10){
            if (partition(x/i, target - x%i)) return 1;
        }
        return 0;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i<=n; i++){
            if (partition(i*i, i)){
                ans+=i*i;
            }
        }
        return ans;
    }
};