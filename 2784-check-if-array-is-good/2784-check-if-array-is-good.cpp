class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int>freq(n, 0);
        for (const int& num: nums) {
            if (num >= n || num <= 0) return false;
            freq[num]++;
            if (freq[num] > 1 && num != n - 1) return false;
            if (freq[num] > 2 && num == n - 1) return false;
        }
        return true;
    }
};