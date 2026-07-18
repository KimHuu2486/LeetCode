class Solution {
public:
    int GCD(int a, int b) {
        if (a < b) {
            swap(a, b);
        }
        if (a % b == 0) return b;
        return GCD(b, a % b);
    }
    int findGCD(vector<int>& nums) {
        int maxEle = *max_element(nums.begin(), nums.end());
        int minEle = *min_element(nums.begin(), nums.end());

        return GCD(maxEle, minEle);
    }
};