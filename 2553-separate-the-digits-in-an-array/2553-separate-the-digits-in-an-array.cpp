class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            while (nums[i] > 0) {
                int digit = nums[i] % 10;
                nums[i] /= 10;
                ans.push_back(digit);
                cnt++;
            }
            reverse(ans.end() - cnt, ans.end());
        }

        return ans;
    }
};