class Solution {
public:
    int check(int& num){
        int cnt = 0;
        int sum = 0;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                sum += i;
                sum += num / i;
                cnt++;
            }
            if (cnt > 1 || i * i == num) {
                return 0;
            }
        }
        return cnt == 0 ? 0 : sum + 1 + num;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int& num: nums) {
            ans += check(num);
        }
        return ans;
    }
};