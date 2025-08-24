class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, right = 0;
        int n = nums.size();
        int zero = 0;
        int ans = 0;
        for (right; right < n; right++) {
            if (nums[right] == 0)
                zero++;
            while (zero > 1) {
                if (nums[left++] == 0)
                    zero--;
            }
            ans = max(ans, right - left + 1 - zero);
        }
        return ans == n ? ans - 1 : ans;
    }
};