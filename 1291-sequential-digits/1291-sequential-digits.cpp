class Solution {
public:
    const int name[8] = {12, 123, 1234, 12345, 123456, 1234567, 12345678, 123456789};
    const int incre[8] = {11, 111, 1111, 11111, 111111, 1111111, 11111111};

    int cntDigit(int num) {
        int ans = 0;
        while (num > 0) {
            num/=10;
            ans++;
        }
        return ans;
    }

    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int cur = name[0];
        int curDigit = 0;
        while (cur < low) {
            if (cur % 10 == 9) {
                curDigit++;
                if (curDigit > 7) return ans;
                cur = name[curDigit];
            }
            else {
                cur = cur + incre[curDigit];
            }
        }

        while (cur <= high) {
            ans.push_back(cur);
            if (cur % 10 == 9) {
                curDigit++;
                if (curDigit > 7) return ans;
                cur = name[curDigit];
            }
            else {
                cur = cur + incre[curDigit];
            }
        }

        return ans;
    }
};