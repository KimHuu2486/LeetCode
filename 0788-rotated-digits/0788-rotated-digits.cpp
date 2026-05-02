class Solution {
public:
    set<int> validNum = {0, 1, 2, 5, 6, 8, 9};
    set<int> validRotate = {2, 5, 6, 9};

    bool isGood(int n) {
        bool isHaveValidRotate = false;
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            if (!validNum.count(digit)) {
                return false;
            }
            if (validRotate.count(digit)) {
                isHaveValidRotate = true;
            }
        }
        return isHaveValidRotate;
    }

    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            if (isGood(i)) {
                ans++;
            }
        }
        return ans;
    }
};